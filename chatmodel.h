#ifndef CHATMODEL_H
#define CHATMODEL_H

#include <QAbstractListModel>

#include "Packages/packages.h"

class ChatModel : public QAbstractListModel {
  Q_OBJECT

 public:
  enum { UsernameRole = Qt::UserRole, MessageRole };

  explicit ChatModel(QObject* parent = nullptr);

  int rowCount(const QModelIndex& parent = QModelIndex()) const override;

  QVariant data(const QModelIndex& index, int role = Qt::DisplayRole) const override;

  void append(MessagePackage user_message);

  QHash<int, QByteArray> roleNames() const override;

 private:
  QHash<int, QByteArray> role_names;
  QList<MessagePackage> user_messages;
};

#endif  // CHATMODEL_H
