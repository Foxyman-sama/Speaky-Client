import QtQuick 2.15
import QtQuick.Controls 2.15
import QtQuick.Layouts 2.15

Rectangle {
  id: page
  color: "#D9D9D9"

  Chat {
    anchors.bottom: bottom_panel.top
  }

  TextField {
    id: text_field

    horizontalAlignment: Text.AlignHCenter
    anchors.bottom: bottom_panel.top
    anchors.left: parent.left
    anchors.right: parent.right

    width: 412
    height: 123
    clip: true
    // @disable-check M16
    color: "black"
    font.pixelSize: 24
    font.family: "Inter"
    // @disable-check M16
    wrapMode: Text.WrapAnywhere
    // @disable-check M16
    background: Rectangle {
      radius: 15
      border.width: 2
    }
  }

  BottomPanel {
    id: bottom_panel
  }
}
