#include <napi.h>

#include "QtCore/QColor/qcolor_wrap.h"
#include "QtCore/QObject/qobject_wrap.h"
#include "QtCore/QPoint/qpoint_wrap.h"
#include "QtCore/QRect/qrect_wrap.h"
#include "QtCore/QSize/qsize_wrap.h"
#include "QtCore/QUrl/qurl_wrap.h"
#include "QtCore/QVariant/qvariant_wrap.h"
#include "QtGui/QApplication/qapplication_wrap.h"
#include "QtGui/QClipboard/qclipboard_wrap.h"
#include "QtGui/QCursor/qcursor_wrap.h"
#include "QtGui/QEvent/QKeyEvent/qkeyevent_wrap.h"
#include "QtGui/QEvent/QMouseEvent/qmouseevent_wrap.h"
#include "QtGui/QFont/qfont_wrap.h"
#include "QtGui/QFontDatabase/qfontdatabase_wrap.h"
#include "QtGui/QIcon/qicon_wrap.h"
#include "QtGui/QKeySequence/qkeysequence_wrap.h"
#include "QtGui/QMovie/qmovie_wrap.h"
#include "QtGui/QPixmap/qpixmap_wrap.h"
#include "QtGui/QStyle/qstyle_wrap.h"
#include "QtWidgets/QAction/qaction_wrap.h"
#include "QtWidgets/QBoxLayout/qboxlayout_wrap.h"
#include "QtWidgets/QCheckBox/qcheckbox_wrap.h"
#include "QtWidgets/QComboBox/qcombobox_wrap.h"
#include "QtWidgets/QDial/qdial_wrap.h"
#include "QtWidgets/QFileDialog/qfiledialog_wrap.h"
#include "QtWidgets/QGridLayout/qgridlayout_wrap.h"
#include "QtWidgets/QGroupBox/qgroupbox_wrap.h"
#include "QtWidgets/QLabel/qlabel_wrap.h"
#include "QtWidgets/QLayout/qlayout_wrap.h"
#include "QtWidgets/QLineEdit/qlineedit_wrap.h"
#include "QtWidgets/QMainWindow/qmainwindow_wrap.h"
#include "QtWidgets/QMenu/qmenu_wrap.h"
#include "QtWidgets/QMenuBar/qmenubar_wrap.h"
#include "QtWidgets/QPainter/qpainter_wrap.h"
#include "QtWidgets/QPlainTextEdit/qplaintextedit_wrap.h"
#include "QtWidgets/QProgressBar/qprogressbar_wrap.h"
#include "QtWidgets/QPushButton/qpushbutton_wrap.h"
#include "QtWidgets/QRadioButton/qradiobutton_wrap.h"
#include "QtWidgets/QScrollArea/qscrollarea_wrap.h"
#include "QtWidgets/QShortcut/qshortcut_wrap.h"
#include "QtWidgets/QSpinBox/qspinbox_wrap.h"
#include "QtWidgets/QStackedWidget/qstackedwidget_wrap.h"
#include "QtWidgets/QSystemTrayIcon/qsystemtrayicon_wrap.h"
#include "QtWidgets/QTabWidget/qtabwidget_wrap.h"
#include "QtWidgets/QTableWidget/qtablewidget_wrap.h"
#include "QtWidgets/QTableWidgetItem/qtablewidgetitem_wrap.h"
#include "QtWidgets/QToolButton/qtoolbutton_wrap.h"
#include "QtWidgets/QTreeWidget/qtreewidget_wrap.h"
#include "QtWidgets/QTreeWidgetItem/qtreewidgetitem_wrap.h"
#include "QtWidgets/QWidget/qwidget_wrap.h"
#include "core/FlexLayout/flexlayout_wrap.h"
// These cant be instantiated in JS Side
void InitPrivateHelpers(Napi::Env env) {
  extrautils::initAppSettings();
  QLayoutWrap::init(env);  // Abstact class wrapper for pointing to any layout
}

Napi::Object Main(Napi::Env env, Napi::Object exports) {
  InitPrivateHelpers(env);
  QApplicationWrap::init(env, exports);
  QObjectWrap::init(env, exports);
  QVariantWrap::init(env, exports);
  QSizeWrap::init(env, exports);
  QRectWrap::init(env, exports);
  QPointWrap::init(env, exports);
  QColorWrap::init(env, exports);
  QUrlWrap::init(env, exports);
  QClipboardWrap::init(env, exports);
  QWidgetWrap::init(env, exports);
  QPixmapWrap::init(env, exports);
  QKeySequenceWrap::init(env, exports);
  QFontDatabaseWrap::init(env, exports);
  QIconWrap::init(env, exports);
  QFontWrap::init(env, exports);
  QMovieWrap::init(env, exports);
  QStyleWrap::init(env, exports);
  QCursorWrap::init(env, exports);
  QComboBoxWrap::init(env, exports);
  QBoxLayoutWrap::init(env, exports);
  QFileDialogWrap::init(env, exports);
  QTableWidgetWrap::init(env, exports);
  QTableWidgetItemWrap::init(env, exports);
  QPainterWrap::init(env, exports);
  QTreeWidgetWrap::init(env, exports);
  QTreeWidgetItemWrap::init(env, exports);
  QGridLayoutWrap::init(env, exports);
  QGroupBoxWrap::init(env, exports);
  FlexLayoutWrap::init(env, exports);
  QMainWindowWrap::init(env, exports);
  QPushButtonWrap::init(env, exports);
  QToolButtonWrap::init(env, exports);
  QSpinBoxWrap::init(env, exports);
  QCheckBoxWrap::init(env, exports);
  QProgressBarWrap::init(env, exports);
  QRadioButtonWrap::init(env, exports);
  QStackedWidgetWrap::init(env, exports);
  QTabWidgetWrap::init(env, exports);
  QLineEditWrap::init(env, exports);
  QKeyEventWrap::init(env, exports);
  QMouseEventWrap::init(env, exports);
  QPlainTextEditWrap::init(env, exports);
  QDialWrap::init(env, exports);
  QLabelWrap::init(env, exports);
  QScrollAreaWrap::init(env, exports);
  QSystemTrayIconWrap::init(env, exports);
  QActionWrap::init(env, exports);
  QShortcutWrap::init(env, exports);
  QMenuWrap::init(env, exports);
  QMenuBarWrap::init(env, exports);
  return exports;
}

NODE_API_MODULE(NODE_GYP_MODULE_NAME, Main)