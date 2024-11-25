import QtQuick 2.15
import QtQuick.Controls 2.15
import QtQuick.Layouts 2.15
import ChatModel 1.0

ListView {
  id: root

  anchors.top: parent.top
  anchors.left: parent.left
  anchors.right: parent.right

  topMargin: 48
  leftMargin: 22
  rightMargin: 22
  bottomMargin: 48
  spacing: 24
  clip: true

  model: chat_model
  delegate: MessageBox {
    sender_name: model.username
    message_box_text: model.message
  }
}
