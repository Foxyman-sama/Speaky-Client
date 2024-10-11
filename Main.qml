import QtQuick
import QtQuick.Controls
import QtQuick.Layouts

ApplicationWindow {
    width: 412
    height: 794
    visible: true
    title: qsTr("Hello World")

    Page {
        id: page
        anchors.fill: parent

        ListView {
            id: list_view
            anchors.top: parent.top
            anchors.left: parent.left
            anchors.right: parent.right
            anchors.bottom: text_field.top
            topMargin: 48
            leftMargin: 22
            rightMargin: 22
            bottomMargin: 48
            spacing: 24
            model: ["Hello, Guys!", "YOU LOVE ME MORE",
                "I really hate bananas and kebabs. Why? Idk, guys", "I really hate bananas and kebabs. Why? Idk, guys",
                "I really hate bananas and kebabs. Why? Idk, guys", "I really hate bananas and kebabs. Why? Idk, guys"]
            delegate: Rectangle {
                color: "#443737"
                radius: 15
                width: list_view.width - list_view.leftMargin - list_view.rightMargin
                height: message.height + 38

                Text {
                    id: message
                    text: modelData
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
                    anchors.left: parent.left
                }

                Button {
                    text: "Отключить"
                    Layout.preferredWidth: frame.button_width
                    Layout.preferredHeight: frame.button_height
                    anchors.right: parent.right
                }
            }
        }
    }

}
