#ifndef CHATMODEL_H
#define CHATMODEL_H

#include <QAbstractListModel>

struct UserMessage {
  QString username;
  QString message;
};

class ChatModel : public QAbstractListModel {
  Q_OBJECT

 public:
  enum { UsernameRole = Qt::UserRole, MessageRole };

  explicit ChatModel(QObject* parent = nullptr);

  int rowCount(const QModelIndex& parent = QModelIndex()) const override;

  QVariant data(const QModelIndex& index, int role = Qt::DisplayRole) const override;

  void append(UserMessage user_message);

  QHash<int, QByteArray> roleNames() const override;

 private:
  QHash<int, QByteArray> role_names;
  QList<UserMessage> user_messages;
};

#endif  // CHATMODEL_H
