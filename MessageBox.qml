import QtQuick
import QtQuick.Layouts

Item {
    required property string modelData

    property alias message_box_text: message.text
    property color message_box_color: "#443737"

    id: root
    width: parent.width
    height: message_box.height + 10

    ColumnLayout {
    anchors.fill: parent
    Text {
        Layout.alignment: Qt.AlignHCenter

        text: "Dima"
        color: "white"
    }

    Rectangle {
        Layout.alignment: Qt.AlignHCenter
        Layout.fillWidth: true
        Layout.preferredHeight: message.height + 38

        id: message_box
        color: message_box_color
        radius: 15

        Text {
            id: message
            anchors.centerIn: parent
            width: parent.width - 50
            color: "white"
            font.pixelSize: 24
            font.family: "Inter"
            wrapMode: Text.WrapAnywhere
            horizontalAlignment: Text.AlignHCenter
        }
    }
    }
}
