#include "chatmodel.h"

ChatModel::ChatModel(QObject* parent) : QAbstractListModel(parent) {}

int ChatModel::rowCount(const QModelIndex& parent) const {
  // For list models only the root node (an invalid parent) should return the list's size. For all
  // other (valid) parents, rowCount() should return 0 so that it does not become a tree model.
  if (parent.isValid()) return 0;

  // FIXME: Implement me!
  return 100;
}

QVariant ChatModel::data(const QModelIndex& index, int role) const {
  if (!index.isValid()) return QVariant();

  switch (role) {
    case UsernameRole:
      return QVariant { "Dima" };
    case MessageRole:
      return QVariant { QString { "Hello, World!" } };
  }

  return QVariant();
}

bool ChatModel::setData(const QModelIndex& index, const QVariant& value, int role) {
  if (data(index, role) != value) {
    // FIXME: Implement me!
    emit dataChanged(index, index, { role });
    return true;
  }
  return false;
}

Qt::ItemFlags ChatModel::flags(const QModelIndex& index) const {
  if (!index.isValid()) return Qt::NoItemFlags;

  return QAbstractItemModel::flags(index) | Qt::ItemIsEditable;  // FIXME: Implement me!
}

QHash<int, QByteArray> ChatModel::roleNames() const {
  QHash<int, QByteArray> names;
  names[UsernameRole] = "username";
  names[MessageRole] = "message";
  return names;
}
