import QtQuick
import QtQuick.Controls
import QtQuick.Layouts

Item {
    property double button_width: 164
    property double button_height: 68

    id: root
    anchors.bottom: parent.bottom
    anchors.left: parent.left
    anchors.right: parent.right
    anchors.bottomMargin: 31

    height: button_height + 20

    RowLayout {
        anchors.fill: parent

        Button {
            Layout.preferredWidth: root.button_width
            Layout.preferredHeight: root.button_height
            Layout.alignment: Qt.AlignLeft
            Layout.leftMargin: 6

            background: Rectangle {
                id: area_first_button
                radius: 15
                color: "#2B9832"

                Text {
                    text: "Отправить"
                    color: "white"
                    anchors.centerIn: parent
                    font.pixelSize: 24
                    font.family: "Inter"
                }
            }

            MouseArea {
                anchors.fill: parent
                hoverEnabled: true
                onEntered: area_first_button.color.g -= 35
                onExited: area_first_button.color.g += 35
            }
        }

        Button {
            Layout.preferredWidth: root.button_width
            Layout.preferredHeight: root.button_height
            Layout.alignment: Qt.AlignRight
            Layout.rightMargin: 6

            background: Rectangle {
                id: area_second_button
                radius: 15
                color: "#982B46"

                Text {
                    text: "Отключить"
                    color: "white"
                    anchors.centerIn: parent
                    font.pixelSize: 24
                    font.family: "Inter"
                }
            }

            MouseArea {
                anchors.fill: parent
                hoverEnabled: true
                onEntered: area_second_button.color.g -= 35
                onExited: area_second_button.color.g += 35
            }
        }
    }
}
