#include "chatmodel.h"

ChatModel::ChatModel(QObject* parent) : QAbstractListModel(parent) {
  role_names[UsernameRole] = "username";
  role_names[MessageRole] = "message";
}

int ChatModel::rowCount(const QModelIndex& parent) const {
  Q_UNUSED(parent);
  return user_messages.count();
}

QVariant ChatModel::data(const QModelIndex& index, int role) const {
  const auto row { index.row() };
  if (row < 0 || row >= user_messages.count()) {
    return QVariant {};
  }

  const auto& current_value { user_messages.at(row) };
  switch (role) {
    case UsernameRole:
      return QString::fromStdString(current_value.username);
    case MessageRole:
      return QString::fromStdString(current_value.text);
  }

  return QVariant();
}

void ChatModel::append(MessagePackage user_message) {
  emit beginInsertRows(QModelIndex {}, user_messages.count(), user_messages.count());
  user_messages.insert(user_messages.count(), user_message);
  emit endInsertRows();
}

QHash<int, QByteArray> ChatModel::roleNames() const { return role_names; }
