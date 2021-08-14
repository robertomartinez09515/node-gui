#pragma once
#include <QAbstractItemModel>

#include "Extras/Export/export.h"
#include "QtCore/QObject/qobject_macro.h"
#include "core/NodeWidget/nodewidget.h"
#include "QtCore/QModelIndex/qmodelindex_wrap.h"

#include "napi.h"

class DLL_EXPORT NAbstractItemModel : public QAbstractItemModel, public EventWidget {
  Q_OBJECT
  EVENTWIDGET_IMPLEMENTATIONS(QAbstractItemModel)
 public:
  Napi::FunctionReference dispatchOnNode;

  void connectSignalsToEventEmitter() {
    // Qt Connects: Implement all signal connects here
    QOBJECT_SIGNALS
  }

  QModelIndex index(int row, int column, const QModelIndex &parent = QModelIndex()) const override {
    Napi::Env env = this->dispatchOnNode.Env();
    Napi::HandleScope scope(env);

    auto parentModelIndexWrap = QModelIndexWrap::constructor.New({Napi::External<QModelIndex>::New(env, new QModelIndex(parent))});
    Napi::Value modelIndexNapiWrap = this->dispatchOnNode.Call(
        {Napi::String::New(env, "index"), Napi::Value::From(env, row), Napi::Value::From(env, column), parentModelIndexWrap});

    QModelIndexWrap* modelIndexWrap = Napi::ObjectWrap<QModelIndexWrap>::Unwrap(modelIndexNapiWrap.As<Napi::Object>());
    QModelIndex* newIndex = modelIndexWrap->getInternalInstance();
    return *newIndex;
  }

  QModelIndex parent(const QModelIndex &child) const override {
    Napi::Env env = this->dispatchOnNode.Env();
    Napi::HandleScope scope(env);

    auto childModelIndexWrap = QModelIndexWrap::constructor.New({Napi::External<QModelIndex>::New(env, new QModelIndex(child))});
    Napi::Value modelIndexNapiWrap = this->dispatchOnNode.Call({Napi::String::New(env, "parent"), childModelIndexWrap});

    QModelIndexWrap* modelIndexWrap = Napi::ObjectWrap<QModelIndexWrap>::Unwrap(modelIndexNapiWrap.As<Napi::Object>());
    QModelIndex* parentIndex = modelIndexWrap->getInternalInstance();
    return *parentIndex;
  }

  int rowCount(const QModelIndex &parent = QModelIndex()) const override {
    Napi::Env env = this->dispatchOnNode.Env();
    Napi::HandleScope scope(env);

    auto modelIndexWrap = QModelIndexWrap::constructor.New({Napi::External<QModelIndex>::New(env, new QModelIndex(parent))});
    Napi::Value result = this->dispatchOnNode.Call({Napi::String::New(env, "rowCount"), modelIndexWrap});

    return result.As<Napi::Number>().Int32Value();
  }

  int columnCount(const QModelIndex &parent = QModelIndex()) const override {
    Napi::Env env = this->dispatchOnNode.Env();
    Napi::HandleScope scope(env);

    auto modelIndexWrap = QModelIndexWrap::constructor.New({Napi::External<QModelIndex>::New(env, new QModelIndex(parent))});
    Napi::Value result = this->dispatchOnNode.Call({Napi::String::New(env, "columnCount"), modelIndexWrap});
    return result.As<Napi::Number>().Int32Value();
  }

  QVariant data(const QModelIndex &index, int role = Qt::DisplayRole) const override {
    Napi::Env env = this->dispatchOnNode.Env();
    Napi::HandleScope scope(env);

    auto modelIndexWrap = QModelIndexWrap::constructor.New({Napi::External<QModelIndex>::New(env, new QModelIndex(index))});
    auto roleValue = Napi::Value::From(env, role);
    Napi::Value variantJsObject = this->dispatchOnNode.Call({Napi::String::New(env, "data"), modelIndexWrap, roleValue});

    QVariantWrap* variantWrap = Napi::ObjectWrap<QVariantWrap>::Unwrap(variantJsObject.As<Napi::Object>());
    QVariant* variant = variantWrap->getInternalInstance();
    return *variant;
  }

  Qt::ItemFlags flags(const QModelIndex &index) const override {
    Napi::Env env = this->dispatchOnNode.Env();
    Napi::HandleScope scope(env);

    auto modelIndexWrap = QModelIndexWrap::constructor.New({Napi::External<QModelIndex>::New(env, new QModelIndex(index))});
    Napi::Value numberJs = this->dispatchOnNode.Call({Napi::String::New(env, "flags"), modelIndexWrap});

    auto result = static_cast<Qt::ItemFlags>(numberJs.As<Napi::Number>().Uint32Value());
    return result;
  }

  QModelIndex _protected_createIndex(int row, int column) const {
    return createIndex(row, column);
  }
};
