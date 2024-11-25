import QtQuick 2.15
import QtQuick.Controls 2.15
import QtQuick.Layouts 2.15

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

  model: ListModel {
    id: model

    ListElement {
      name: "Dima"
      message: "Hello!!"
    }

    ListElement {
      name: "Kebab"
      message: "Goodbye!"
    }
  }

  delegate: MessageBox {
    sender_name: name
    message_box_text: message
  }
}
