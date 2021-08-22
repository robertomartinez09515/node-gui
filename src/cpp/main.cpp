#include <napi.h>

#include "Extras/Utils/nutils.h"
#include "QtCore/QAbstractItemModel/qabstractitemmodel_wrap.h"
#include "QtCore/QDate/qdate_wrap.h"
#include "QtCore/QDateTime/qdatetime_wrap.h"
#include "QtCore/QItemSelectionModel/qitemselectionmodel_wrap.h"
#include "QtCore/QMimeData/qmimedata_wrap.h"
#include "QtCore/QModelIndex/qmodelindex_wrap.h"
#include "QtCore/QObject/qobject_wrap.h"
#include "QtCore/QPoint/qpoint_wrap.h"
#include "QtCore/QPointF/qpointf_wrap.h"
#include "QtCore/QRect/qrect_wrap.h"
#include "QtCore/QRectF/qrectf_wrap.h"
#include "QtCore/QSettings/qsettings_wrap.h"
#include "QtCore/QSize/qsize_wrap.h"
#include "QtCore/QTime/qtime_wrap.h"
#include "QtCore/QUrl/qurl_wrap.h"
#include "QtCore/QVariant/qvariant_wrap.h"
#include "QtGui/QApplication/qapplication_wrap.h"
#include "QtGui/QBrush/qbrush_wrap.h"
#include "QtGui/QClipboard/qclipboard_wrap.h"
#include "QtGui/QColor/qcolor_wrap.h"
#include "QtGui/QCursor/qcursor_wrap.h"
#include "QtGui/QDrag/qdrag_wrap.h"
#include "QtGui/QEvent/QDragLeaveEvent/qdragleaveevent_wrap.h"
#include "QtGui/QEvent/QDragMoveEvent/qdragmoveevent_wrap.h"
#include "QtGui/QEvent/QDropEvent/qdropevent_wrap.h"
#include "QtGui/QEvent/QKeyEvent/qkeyevent_wrap.h"
#include "QtGui/QEvent/QMouseEvent/qmouseevent_wrap.h"
#include "QtGui/QEvent/QNativeGestureEvent/qnativegestureevent_wrap.h"
#include "QtGui/QEvent/QPaintEvent/qpaintevent_wrap.h"
#include "QtGui/QEvent/QTabletEvent/qtabletevent_wrap.h"
#include "QtGui/QEvent/QWheelEvent/qwheelevent_wrap.h"
#include "QtGui/QFont/qfont_wrap.h"
#include "QtGui/QFontDatabase/qfontdatabase_wrap.h"
#include "QtGui/QFontMetrics/qfontmetrics_wrap.h"
#include "QtGui/QIcon/qicon_wrap.h"
#include "QtGui/QImage/qimage_wrap.h"
#include "QtGui/QKeySequence/qkeysequence_wrap.h"
#include "QtGui/QMovie/qmovie_wrap.h"
#include "QtGui/QPalette/qpalette_wrap.h"
#include "QtGui/QPen/qpen_wrap.h"
#include "QtGui/QPicture/qpicture_wrap.h"
#include "QtGui/QPixmap/qpixmap_wrap.h"
#include "QtGui/QStyle/qstyle_wrap.h"
#include "QtWidgets/QAction/qaction_wrap.h"
#include "QtWidgets/QBoxLayout/qboxlayout_wrap.h"
#include "QtWidgets/QButtonGroup/qbuttongroup_wrap.h"
#include "QtWidgets/QCalendarWidget/qcalendarwidget_wrap.h"
#include "QtWidgets/QCheckBox/qcheckbox_wrap.h"
#include "QtWidgets/QColorDialog/qcolordialog_wrap.h"
#include "QtWidgets/QComboBox/qcombobox_wrap.h"
#include "QtWidgets/QDateEdit/qdateedit_wrap.h"
#include "QtWidgets/QDateTimeEdit/qdatetimeedit_wrap.h"
#include "QtWidgets/QDesktopWidget/qdesktopwidget_wrap.h"
#include "QtWidgets/QDial/qdial_wrap.h"
#include "QtWidgets/QDialog/qdialog_wrap.h"
#include "QtWidgets/QDoubleSpinBox/qdoublespinbox_wrap.h"
#include "QtWidgets/QErrorMessage/qerrormessage_wrap.h"
#include "QtWidgets/QFileDialog/qfiledialog_wrap.h"
#include "QtWidgets/QFontDialog/qfontdialog_wrap.h"
#include "QtWidgets/QFrame/qframe_wrap.h"
#include "QtWidgets/QGraphicsBlurEffect/qgraphicsblureffect_wrap.h"
#include "QtWidgets/QGraphicsDropShadowEffect/qgraphicsdropshadoweffect_wrap.h"
#include "QtWidgets/QGridLayout/qgridlayout_wrap.h"
#include "QtWidgets/QGroupBox/qgroupbox_wrap.h"
#include "QtWidgets/QHeaderView/qheaderview_wrap.h"
#include "QtWidgets/QInputDialog/qinputdialog_wrap.h"
#include "QtWidgets/QLCDNumber/qlcdnumber_wrap.h"
#include "QtWidgets/QLabel/qlabel_wrap.h"
#include "QtWidgets/QLayout/qlayout_wrap.h"
#include "QtWidgets/QLineEdit/qlineedit_wrap.h"
#include "QtWidgets/QListView/qlistview_wrap.h"
#include "QtWidgets/QListWidget/qlistwidget_wrap.h"
#include "QtWidgets/QListWidgetItem/qlistwidgetitem_wrap.h"
#include "QtWidgets/QMainWindow/qmainwindow_wrap.h"
#include "QtWidgets/QMenu/qmenu_wrap.h"
#include "QtWidgets/QMenuBar/qmenubar_wrap.h"
#include "QtWidgets/QMessageBox/qmessagebox_wrap.h"
#include "QtWidgets/QPainter/qpainter_wrap.h"
#include "QtWidgets/QPainterPath/qpainterpath_wrap.h"
#include "QtWidgets/QPlainTextEdit/qplaintextedit_wrap.h"
#include "QtWidgets/QProgressBar/qprogressbar_wrap.h"
#include "QtWidgets/QProgressDialog/qprogressdialog_wrap.h"
#include "QtWidgets/QPushButton/qpushbutton_wrap.h"
#include "QtWidgets/QRadioButton/qradiobutton_wrap.h"
#include "QtWidgets/QScrollArea/qscrollarea_wrap.h"
#include "QtWidgets/QScrollBar/qscrollbar_wrap.h"
#include "QtWidgets/QShortcut/qshortcut_wrap.h"
#include "QtWidgets/QSlider/qslider_wrap.h"
#include "QtWidgets/QSpinBox/qspinbox_wrap.h"
#include "QtWidgets/QStackedWidget/qstackedwidget_wrap.h"
#include "QtWidgets/QStandardItem/qstandarditem_wrap.h"
#include "QtWidgets/QStandardItemModel/qstandarditemmodel_wrap.h"
#include "QtWidgets/QStatusBar/qstatusbar_wrap.h"
#include "QtWidgets/QSvgWidget/qsvgwidget_wrap.h"
#include "QtWidgets/QSystemTrayIcon/qsystemtrayicon_wrap.h"
#include "QtWidgets/QTabBar/qtabbar_wrap.h"
#include "QtWidgets/QTabWidget/qtabwidget_wrap.h"
#include "QtWidgets/QTableView/qtableview_wrap.h"
#include "QtWidgets/QTableWidget/qtablewidget_wrap.h"
#include "QtWidgets/QTableWidgetItem/qtablewidgetitem_wrap.h"
#include "QtWidgets/QTextBrowser/qtextbrowser_wrap.h"
#include "QtWidgets/QTextEdit/qtextedit_wrap.h"
#include "QtWidgets/QTimeEdit/qtimeedit_wrap.h"
#include "QtWidgets/QToolButton/qtoolbutton_wrap.h"
#include "QtWidgets/QTreeWidget/qtreewidget_wrap.h"
#include "QtWidgets/QTreeWidgetItem/qtreewidgetitem_wrap.h"
#include "QtWidgets/QWidget/qwidget_wrap.h"
#include "core/FlexLayout/flexlayout_wrap.h"
#include "core/Integration/integration.h"
// These cant be instantiated in JS Side
void InitPrivateHelpers(Napi::Env env) {
  qodeIntegration::integrate();
  QLayoutWrap::init(env);  // Abstact class wrapper for pointing to any layout
}

Napi::Object Main(Napi::Env env, Napi::Object exports) {
  InitPrivateHelpers(env);
  NUtilsWrap::init(env, exports);
  QApplicationWrap::init(env, exports);
  QDateWrap::init(env, exports);
  QDateTimeWrap::init(env, exports);
  QMimeDataWrap::init(env, exports);
  QModelIndexWrap::init(env, exports);
  QObjectWrap::init(env, exports);
  QPointWrap::init(env, exports);
  QPointFWrap::init(env, exports);
  QRectWrap::init(env, exports);
  QRectFWrap::init(env, exports);
  QSizeWrap::init(env, exports);
  QTimeWrap::init(env, exports);
  QUrlWrap::init(env, exports);
  QVariantWrap::init(env, exports);
  QBrushWrap::init(env, exports);
  QPenWrap::init(env, exports);
  QColorWrap::init(env, exports);
  QClipboardWrap::init(env, exports);
  QDialogWrap::init(env, exports);
  QWidgetWrap::init(env, exports);
  QPictureWrap::init(env, exports);
  QPixmapWrap::init(env, exports);
  QKeySequenceWrap::init(env, exports);
  QFontDatabaseWrap::init(env, exports);
  QFontMetricsWrap::init(env, exports);
  QIconWrap::init(env, exports);
  QImageWrap::init(env, exports);
  QFontWrap::init(env, exports);
  QMovieWrap::init(env, exports);
  QStyleWrap::init(env, exports);
  QCursorWrap::init(env, exports);
  QCalendarWidgetWrap::init(env, exports);
  QColorDialogWrap::init(env, exports);
  QComboBoxWrap::init(env, exports);
  QDoubleSpinBoxWrap::init(env, exports);
  QBoxLayoutWrap::init(env, exports);
  QDateEditWrap::init(env, exports);
  QDateTimeEditWrap::init(env, exports);
  QErrorMessageWrap::init(env, exports);
  QFileDialogWrap::init(env, exports);
  QFontDialogWrap::init(env, exports);
  QFrameWrap::init(env, exports);
  QGraphicsBlurEffectWrap::init(env, exports);
  QGraphicsDropShadowEffectWrap::init(env, exports);
  QListViewWrap::init(env, exports);
  QListWidgetWrap::init(env, exports);
  QListWidgetItemWrap::init(env, exports);
  QTableViewWrap::init(env, exports);
  QTableWidgetWrap::init(env, exports);
  QTableWidgetItemWrap::init(env, exports);
  QPainterWrap::init(env, exports);
  QPainterPathWrap::init(env, exports);
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
  QProgressDialogWrap::init(env, exports);
  QRadioButtonWrap::init(env, exports);
  QStackedWidgetWrap::init(env, exports);
  QTabBarWrap::init(env, exports);
  QTabWidgetWrap::init(env, exports);
  QLineEditWrap::init(env, exports);
  QKeyEventWrap::init(env, exports);
  QMouseEventWrap::init(env, exports);
  QWheelEventWrap::init(env, exports);
  QTabletEventWrap::init(env, exports);
  QDragWrap::init(env, exports);
  QDropEventWrap::init(env, exports);
  QDragMoveEventWrap::init(env, exports);
  QDragLeaveEventWrap::init(env, exports);
  QNativeGestureEventWrap::init(env, exports);
  QPlainTextEditWrap::init(env, exports);
  QDialWrap::init(env, exports);
  QLabelWrap::init(env, exports);
  QLCDNumberWrap::init(env, exports);
  QScrollAreaWrap::init(env, exports);
  QScrollBarWrap::init(env, exports);
  QSystemTrayIconWrap::init(env, exports);
  QActionWrap::init(env, exports);
  QShortcutWrap::init(env, exports);
  QMenuWrap::init(env, exports);
  QMenuBarWrap::init(env, exports);
  QMessageBoxWrap::init(env, exports);
  QInputDialogWrap::init(env, exports);
  QSliderWrap::init(env, exports);
  QTextBrowserWrap::init(env, exports);
  QTextEditWrap::init(env, exports);
  QTimeEditWrap::init(env, exports);
  QButtonGroupWrap::init(env, exports);
  QStatusBarWrap::init(env, exports);
  QSettingsWrap::init(env, exports);
  QStandardItemModelWrap::init(env, exports);
  QStandardItemWrap::init(env, exports);
  QSvgWidgetWrap::init(env, exports);
  QDesktopWidgetWrap::init(env, exports);
  QPaintEventWrap::init(env, exports);
  QPaletteWrap::init(env, exports);
  QAbstractItemModelWrap::init(env, exports);
  QHeaderViewWrap::init(env, exports);
  QItemSelectionModelWrap::init(env, exports);
  return exports;
}

NODE_API_MODULE(NODE_GYP_MODULE_NAME, Main)
