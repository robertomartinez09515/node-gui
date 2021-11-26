#pragma once

#include <napi.h>

#include <QPointer>
#include <QWindow>

#include "Extras/Export/export.h"
#include "QtCore/QObject/qobject_macro.h"

class DLL_EXPORT QWindowWrap : public Napi::ObjectWrap<QWindowWrap>,
                               public EventWidget {
  QOBJECT_WRAPPED_METHODS_DECLARATION_WITH_EVENT_SOURCE(this)
  // Note: We don't use EVENTWIDGET_IMPLEMENTATIONS() here because this class
  // doesn't handle any QEvents.

 private:
  QPointer<QWindow> instance;

 public:
  // class constructor
  static Napi::FunctionReference constructor;

  static Napi::Object init(Napi::Env env, Napi::Object exports);
  QWindowWrap(const Napi::CallbackInfo& info);
  QWindow* getInternalInstance();

  virtual void connectSignalsToEventEmitter();

  // wrapped methods
  Napi::Value screen(const Napi::CallbackInfo& info);
};
