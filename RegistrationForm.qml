import QtQuick 2.15
import QtQuick.Controls 2.15
import QtQuick.Layouts 2.15

Rectangle {
  property alias input_room_id_text: input_room_id.text
  property alias input_name_text: input_name.text
  signal registrate

  id: root

  ColumnLayout {
    anchors.fill: parent
    Item {
      Layout.fillWidth: true
      Layout.fillHeight: true
    }
    Row {
      Layout.fillWidth: true
      Layout.alignment: Qt.AlignVCenter

      Text {
        id: room_id_label
        text: "Введите номер комнаты:"
      }

      TextField {
        id: input_room_id
      }
    }
    Row {
      Layout.fillWidth: true
      Layout.alignment: Qt.AlignVCenter

      Text {
        id: name_label
        text: "Введите имя:"
      }

      TextField {
        id: input_name
      }
    }
    Button {
      Layout.fillWidth: true

      Text {
        anchors.centerIn: parent
        text: "Зарегистрироваться"
      }

      onClicked: registrate()
    }

    Item {
      Layout.fillWidth: true
      Layout.fillHeight: true
    }
  }
}
