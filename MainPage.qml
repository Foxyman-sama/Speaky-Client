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
        anchors.bottom: bottom_panel.top
        anchors.left: parent.left
        anchors.right: parent.right

        width: 412
        height: 123

        color: "black"
        font.pixelSize: 24
        font.family: "Inter"
        wrapMode: Text.WrapAnywhere

        background: Rectangle {
            radius: 15
            border.width: 2
        }
    }

   BottomPanel {
       id: bottom_panel
   }
}
