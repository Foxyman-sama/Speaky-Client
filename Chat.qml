import QtQuick

ListView {
    id: list_view

    anchors.top: parent.top
    anchors.left: parent.left
    anchors.right: parent.right

    topMargin: 48
    leftMargin: 22
    rightMargin: 22
    bottomMargin: 48
    spacing: 24

    model: ListModel {
        id: model

        ListElement {
            name: "Dima"
            message: "Hello!!"
        }

        ListElement {
            name: "Kebab"
            message: "GoodbyeGoodbyeGoodbyeGoodbyeGoodbyeGoodbyeGoodbyeGoodbyeGoodbyeGoodbyeGoodbyeGoodbyeGoodbyeGoodbyeGoodbyeGoodbye!"
        }
    }

    delegate: MessageBox {
        sender_name: name
        message_box_text: message
    }
}
