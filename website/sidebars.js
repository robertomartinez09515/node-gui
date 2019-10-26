module.exports = {
  api: {
    General: ["api/synopsis"],
    Widgets: [
      "api/QApplication",
      "api/QCheckBox",
      "api/QDial",
      "api/QLabel",
      "api/QLineEdit",
      "api/QMainWindow",
      "api/QPlainTextEdit",
      "api/QProgressBar",
      "api/QPushButton",
      "api/QRadioButton",
      "api/QScrollArea",
      "api/QSpinBox",
      "api/QTabWidget",
      "api/QWidget",
      "api/QMenu",
      "api/QMenuBar"
    ],
    Layouts: ["api/FlexLayout", "api/QGridLayout"],
    Modules: [
      "api/QClipboard",
      "api/QCursor",
      "api/QPixmap",
      "api/QtEnums",
      "api/QShortcut",
      "api/QAction",
      "api/QKeySequence",
      "api/QIcon",
      "api/QSystemTrayIcon"
    ],
    "Internal Modules": [
      "api/Component",
      "api/EventWidget",
      "api/NodeLayout",
      "api/NodeWidget",
      "api/YogaWidget",
      "api/QAbstractScrollArea",
      "api/QAbstractSlider"
    ],
    APIs: ["api/process"]
  },
  guides: {
    "The Basics": [
      "guides/getting-started",
      "guides/tutorial",
      "guides/styling",
      "guides/layout",
      "guides/handle-events",
      "guides/scroll-view",
      "guides/images",
      "guides/networking"
    ],
    Guides: [
      "guides/nodegui-architecture",
      "guides/debugging",
      "guides/debugging-in-vscode",
      "guides/using-native-node-modules",
      "guides/custom-nodegui-native-plugin"
    ]
  }
};
