const path = require("path");
const fs = require("fs");
const childProcess = require("child_process");
const { qtHome } = require("@nodegui/qode");

const ROOT_DIR = path.resolve(__dirname, "../");
const MOC_AUTOGEN_DIR = path.resolve(ROOT_DIR, "src/cpp/autogen");
const MOC_GYPI_FILE = path.resolve(ROOT_DIR, "config/moc.gypi");

const getConfig = () => {
  const configFilePath = path.resolve(ROOT_DIR, "config/moc.json");
  return JSON.parse(fs.readFileSync(configFilePath));
};

const generateCommand = (headerFilePath, includeFilePath) => {
  const infilePath = path.resolve(ROOT_DIR, headerFilePath);
  const parsed = path.parse(infilePath);
  const outfilePath = path.format({
    dir: MOC_AUTOGEN_DIR,
    name: `${parsed.name}_moc`,
    ext: ".cpp"
  });
  const command = `moc ${infilePath} -o ${outfilePath} --include ${includeFilePath}`;
  return {
    command,
    infilePath,
    outfilePath
  };
};

const generateMocGypiFile = outFilePaths => {
  const sources = outFilePaths.map(eachOutFilePath => {
    return path.relative(path.parse(MOC_GYPI_FILE).dir, eachOutFilePath);
  });

  const gypiConfig = {
    sources: sources
  };
  const comment = `# AUTOGENERATED FILE. DO NOT MODIFY . ALL CHANGES WILL BE LOST\n# RUN: npm run automoc after updating moc.json\n`;
  console.log("Updating moc.gypi...");
  const fileContent = JSON.stringify(gypiConfig, null, 4);
  fs.writeFileSync(MOC_GYPI_FILE, comment.concat(fileContent));
  console.log("Updated moc.gypi");
};

const main = () => {
  const config = getConfig();
  const includeFilePath = path.resolve(ROOT_DIR, config.include);
  const outFiles = config.headers.map(eachHeaderPath => {
    const { command, outfilePath } = generateCommand(
      eachHeaderPath,
      includeFilePath
    );
    const mocPath = path.resolve(process.env.QT_INSTALL_DIR || qtHome, "bin");
    childProcess.exec(
      command,
      {
        env: {
          ...process.env,
          PATH: `${mocPath}${path.delimiter}${process.env.PATH}`
        }
      },
      error => {
        if (error) {
          console.error(`exec error: ${error}`);
          return;
        }
      }
    );
    return outfilePath;
  });
  generateMocGypiFile(outFiles);
};

main();
