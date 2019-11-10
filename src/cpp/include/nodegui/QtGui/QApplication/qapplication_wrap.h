#pragma once

#include <napi.h>

#include <QApplication>
#include <QPointer>

#include "core/Component/component_macro.h"

class QApplicationWrap : public Napi::ObjectWrap<QApplicationWrap> {
 private:
  QPointer<QApplication> instance;
  static int argc;
  static char** argv;
  bool _wasManuallyCreated = false;

 public:
  static Napi::FunctionReference constructor;
  static Napi::Object init(Napi::Env env, Napi::Object exports);
  QApplicationWrap(const Napi::CallbackInfo& info);
  ~QApplicationWrap();
  QApplication* getInternalInstance();
  // Wrapped methods
  Napi::Value processEvents(const Napi::CallbackInfo& info);
  Napi::Value exec(const Napi::CallbackInfo& info);
  Napi::Value quit(const Napi::CallbackInfo& info);
  Napi::Value exit(const Napi::CallbackInfo& info);
  Napi::Value setQuitOnLastWindowClosed(const Napi::CallbackInfo& info);
  Napi::Value quitOnLastWindowClosed(const Napi::CallbackInfo& info);

  COMPONENT_WRAPPED_METHODS_DECLARATION
};

namespace StaticQApplicationWrapMethods {
Napi::Value instance(const Napi::CallbackInfo& info);
Napi::Value clipboard(const Napi::CallbackInfo& info);
}  // namespace StaticQApplicationWrapMethods