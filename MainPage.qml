import QtQuick
import QtQuick.Controls
import QtQuick.Layouts

Page {
    id: page
    anchors.fill: parent
    background: Rectangle {
        color: "#D9D9D9"
    }

    Chat {
         anchors.bottom: text_field.top
    }

    TextField {
        id: text_field
        horizontalAlignment: Text.AlignHCenter
        anchors.bottom: frame.top
        anchors.left: parent.left
        anchors.right: parent.right
        width: 412
        height: 123
    }

    Frame {
        property double button_width: 164
        property double button_height: 68

        id: frame
        anchors.bottom: parent.bottom
        anchors.left: parent.left
        anchors.right: parent.right
        anchors.bottomMargin: 31
        height: button_height + 20

        RowLayout {
            anchors.fill: parent

            Button {
                text: "Отправить"
                Layout.preferredWidth: frame.button_width
                Layout.preferredHeight: frame.button_height
            }

            Button {
                text: "Отключить"
                Layout.preferredWidth: frame.button_width
                Layout.preferredHeight: frame.button_height
            }
        }
    }
}
