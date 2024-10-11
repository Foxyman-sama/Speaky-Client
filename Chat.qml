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
            message: "Goodbye!"
        }
    }

    delegate: MessageBox {
        sender_name: model.name
        message_box_text: message
    }
}
