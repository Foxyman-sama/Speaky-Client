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

  // Basic functionality:
  int rowCount(const QModelIndex& parent = QModelIndex()) const override;

  QVariant data(const QModelIndex& index, int role = Qt::DisplayRole) const override;

  // Editable:
  bool setData(const QModelIndex& index, const QVariant& value, int role = Qt::EditRole) override;

  void addUserMessage(UserMessage user_message);

  Qt::ItemFlags flags(const QModelIndex& index) const override;

  QHash<int, QByteArray> roleNames() const override;

 private:
  std::vector<UserMessage> user_messages;
};

#endif  // CHATMODEL_H
