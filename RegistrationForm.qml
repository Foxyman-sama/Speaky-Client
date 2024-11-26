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

    RowLayout {
      Layout.fillWidth: true
      Layout.alignment: Qt.AlignVCenter
      Layout.leftMargin: 10
      Layout.rightMargin: 10

      Text {
        id: room_id_label
        text: "Введите номер комнаты:"
      }

      TextField {
        Layout.fillWidth: true

        id: input_room_id
      }
    }

    RowLayout {
      Layout.fillWidth: true
      Layout.alignment: Qt.AlignVCenter
      Layout.leftMargin: 10
      Layout.rightMargin: 10

      Text {
        id: name_label
        text: "Введите имя:"
      }

      TextField {
        Layout.fillWidth: true

        id: input_name
      }
    }

    Button {
      Layout.fillWidth: true
      Layout.alignment: Qt.AlignVCenter
      Layout.leftMargin: 10
      Layout.rightMargin: 10

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
