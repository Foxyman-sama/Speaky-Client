import QtQuick
import QtQuick.Controls
import QtQuick.Layouts

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
            Layout.preferredWidth: frame.button_width
            Layout.preferredHeight: frame.button_height
            Layout.alignment: Qt.AlignLeft

            background: Rectangle {
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
        }

        Button {
            Layout.preferredWidth: frame.button_width
            Layout.preferredHeight: frame.button_height
            Layout.alignment: Qt.AlignRight

            background: Rectangle {
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
        }
    }
}
