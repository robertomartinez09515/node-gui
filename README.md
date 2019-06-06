# node-native-ui

A cross platform library to build native desktop apps. Based on Qt5.

Mac screenshots:

![mac](https://github.com/master-atul/node-native-ui/raw/master/screens/mac_dark_mode.png "Mac OS Dark screenshot")
![mac](https://github.com/master-atul/node-native-ui/raw/master/screens/mac_light_mode.png "Mac OS Light screenshot")

Linux and Windows screenshots to be added soon.

## Features

- [x] Cross platform. Should work on major Linux flavours, Windows and MacOS
- [x] Low CPU and memory footprint. Current CPU stays at 0% on idle and memory usage is under 20mb for a hello world program.
- [ ] (Partial support is present) Easily exstensible for creating custom native widgets (like react native).
- [x] Support for flex box layouting using Yoga.
- [x] Supports styling using css (includes actual cascading) or atleast useful subset of css properties.
- [x] Complete Nodejs api support (Currently runs on Node v12 - and is easily upgradable).
- [x] Can use all node compatible npm modules.
- [ ] Native widget event listener support.
- [x] Should be usable for commercial applications aswell.
- [ ] (Partial) Should have a decent list of stylable native widgets.
- [ ] Easy build and packaging process.
- [ ] Good Devtools support (hot reload, live reload, debugging etc).
- [ ] Good documentation and website.
- [ ] Good documentation for contributors.
- [x] Good support for dark mode (Thanks to QT).
- [x] Typescript support

## Development setup and getting started

This guide is for setting up `node-native-ui` for contributors of node-native-ui.
The actual getting started guide for users will be added once we reach a bit of stable level.

Make sure you have setup `qode` and installed it globally.

### MacOSX:

**Requirements**

1. Node version: > 9
2. Python and gcc
3. Make sure you dont have spaces inside your home path. NodeGYP has issues with spaces in the path. https://github.com/nodejs/node-gyp/issues/209

**Setting up**

1. Install latest version of Qt (5.12) via homebrew only.

```
brew install qt5
```

### Windows:

**Requirements**

1. Node version: > 9
2. Python and MSVC++

**Setting up**
-- Instructions will be added soon --

### Linux:

**Requirements**

1. Node version: > 9
2. Python, Make, GCC, pkg-config and Qt5 <br/>

On Ubuntu: `$ sudo apt-get install pkg-config build-essentials` should install everything except Qt5.

**Setting up**

1. Make sure you have downloaded and installed Qt5 sdk.
2. Before running `yard build`, do
   `export PKG_CONFIG_PATH="<path to qt installation>/5.11.0/gcc_64/lib/pkgconfig"`

### Common:

1. Once you have setup the platform specific stuff as mentioned above, follow these:

2. `git clone` this repo.

3. Keep note of the install directory of qt. You should probably find it at `/usr/local/Cellar/qt/5.12.1`. Copy this path and
   edit the file `config/common.gypi`. <br/>
   Change the field

   ```
   'qt_home_dir': '<!(echo $QN_QT_HOME_DIR)',
   ```

   to

   ```
   'qt_home_dir': '/usr/local/Cellar/qt/5.12.1',
   ```

4. `yarn install`
5. `yarn build:addon`
6. `yarn dev`

## Learning Materials:

1. Beginners guide to NodeJS Addon - https://medium.com/@atulanand94/beginners-guide-to-writing-nodejs-addons-using-c-and-n-api-node-addon-api-9b3b718a9a7f
2. First read this: N-API in nodejs docs
3. https://www.youtube.com/watch?v=-Oniup60Afs&feature=youtu.be
4. See samples at https://github.com/nodejs/abi-stable-node-addon-examples/
   4.1. You can see the readme of https://github.com/nodejs/node-addon-api.git/
5. See node-qt implementation. It is implemented in Nan (explained in video).
6. Now try to match the implementation in node-qt and convert to N-API using examples from samples.
7. Implementations not in node-qt need to be done with effort.

## What is this library ?

This library aims to be a nodejs addon which can export Qt Widgets to the Javascript world. By doing so one can develop fully fledged cross platform native GUI applications using only Javascript.

The library depends on `qode` which is a lightly modified version of NodeJS. The slight modification was needed to make it work with this addon. In essense, we will do `qode your_file.js` instead of `node your_file.js`.

Qode is inspired by this post by [Cheng Zhao](https://github.com/zcbenz): https://electronjs.org/blog/electron-internals-node-integration

This library does not modify Qt in any way and only use it as it is. This library also dynamically links to Qt. So it needs Qt libs to be installed in your system to work (This is done to keep in compliance with open source LGPL license of Qt). We can think of exporting the required libs later.

## Code Structure

```
.
├── binding.gyp
├── config
├── demo.ts
├── package.json
├── src
│   ├── cpp    <-- C++ source code
│   └── lib    <-- Typescript source code
├── tsconfig.json
└── yarn.lock
```

The main folder is `src`. It contains

- `cpp` : This folder contains all the C++ source code. Basically all the wrapper code using NAPI to export Qt Widgets and other helper functions to Javascript.
- `lib` : This folder contains all the Typescript code of the library. This is used to add additonal helper methods and types to exported addon.

**Detailed version:**

```
.
├── binding.gyp
├── config
│   ├── application.gypi
│   ├── common.gypi
│   └── yoga.gypi
├── demo.ts
├── package.json
├── src
│   ├── cpp
│   │   ├── Extras
│   │   ├── QtGui         <------ All exported classes found inside Qts Gui dynamic library
│   │   ├── QtWidgets     <------ All exported classes found inside Qts Widgets dynamic library
│   │   ├── core
│   │   └── main.cpp
│   └── lib
│       ├── QtGui
│       ├── QtWidgets
│       └── core
├── tsconfig.json
└── yarn.lock

```

First step to seeing how everything works is to take a look at `demo.ts` file. This file is basically like a Kitchen application showcasing all the exported widgets currently with the library.

Make sure you have read how to write native NodeJS Addons blog first. https://medium.com/@atulanand94/beginners-guide-to-writing-nodejs-addons-using-c-and-n-api-node-addon-api-9b3b718a9a7f

Once you have done that check out `src/cpp/main.cpp` and `config/application.gypi` to see the list of exported C++ classes.

Then maybe you can take a look at `src/cpp/QtWidgets/QLabel/qlabel_wrap.h`. This will show you how to wrap a simple Qt Widget.
Check the corresponding JS file for the addon here `src/lib/QtWidgets/QLabel/index.ts`.

## General Idea for Wrapping a widget.

Create wrappers for each and every Qt class that you will use with N-API (using node-addon-api since it is c++) and export it onto JS side.

Taking the example of QLabel, if you look inside the directory `src/cpp/QtWidgets/QLabel`, you should see:

```
├── QLabel
│   ├── nlabel.cpp
│   ├── nlabel.h     <---- Extended QLabel
│   ├── nlabel_moc.cpp <--- Autogenerated file by qt moc.
│   ├── qlabel_wrap.cpp
│   └── qlabel_wrap.h <--- Wrapper file
```

The idea is :

1. We will first extend QLabel class to form NLabel. NLabel is basically QLabel with some extra methods and variables. More on it below.
2. Then we will use NLabel and wrap it using NAPI and export it to JS side. This is what qlabel_wrap does.

**NLabel**: Since NLabel has inherited from QLabel we can treat is as QLabel with extra methods and properties. Primary reason to extend QLabel to create NLabel is to add support for Event listeners and CSS styling using Flex.
So if you take a look at NLabel you will see, it inherits from QLabel and YogaWidget. It would in future inherit from more classes that implement event listeners etc. YogaWidget is a class that contains the magic that enables a regular Qt Widget to have Yoga node. A Yoga node is an instance used by yoga library to calculate a widgets position on the screen. Yoga is a library that will layout the widget on the screen. To do so we will specify the flex properties like alignitems, justify content, margin, paddings etc on the Yoga node of the widget. Apart from adding yoga node, YogaWidget adds support for specifying those yoga properties via Qt's stylesheet. (This is done by using Q_PROPERTY). To make this work we need to use something called as Q_OBJECT inside the class which is a C++ macro. Q_OBJECT will be expanded to relevant code by the compiler. In Qt whenever we add Q_OBJECT to a header file, we need to use a pre compiler called Qt MOC (Meta Object Compiler). The way we use it is

```
moc headername.h -o headername_moc.cpp
```

This will run moc on `headername.h` and generate `headername_moc.cpp`. We will include this file instead of `headername.h`. This is the reason we have `nlabel_moc.cpp`. If you dont do this. Then it will give a symbol not found error.

I hope QLabel's example is enough for now. For more examples and inspirations we can take a look at other wrapped widgets.

# DEBUGGING

https://medium.com/@atulanand94/debugging-nodejs-c-addons-using-vs-code-27e9940fc3ad

https://medium.com/cameron-nokes/how-to-debug-native-node-addons-in-mac-osx-66f69f81afcb

### LICENSE

Since we do not in any way modify the code of Qt and only link to it dynamically, I beleive we are in compliance with the LGPL license requirements of QT. And hence this library can be licensed under its own License (for which we have chosen MIT License).
The links to QT source code and appropriate license notices are attached. We try our best to abide by the software licenses and any non compliance is not by will. If there is some discrepancy please let us know in the issues and we will try and fix it up.
If you follow the recommended build steps and do not statically link QT libraries on your own you are safe to use this library for commerical puropses (provided you abide by MIT License).

MIT

### Notes (Personal)

**Yoga related**

- Need to implement YGMeasure for labels and text
- Need to implement width and height via stylesheet
- Need to implement custom autoprefixer

**MOC related**

- Qt's moc doesnt work with macros well if used separately. Current work around is to not use a macro in file having Q_OBJECT.
  This invloves copy pasting a big chunck of code. Need to find a fix for that.
- Auto run qt's moc on files having Q_OBJECT

**Debug logs**

- Need a setup where we can run the program with debug mode on and it shows logs.
