import QtQuick 2.15
import QtQuick.Controls 2.15
import QtQuick.Layouts 2.15

ApplicationWindow {
  width: 412
  height: 794
  visible: true
  title: qsTr("Hello World")
  minimumWidth: 412
  minimumHeight: 794

  StackView {
    id: stack
    initialItem: registration_form
    anchors.fill: parent
  }
  // @disable-check M300
  Backend {
    id: backend
  }

  Component {
    id: main_page
    MainPage {}
  }

  RegistrationForm {
    id: registration_form
    onRegistrate: {
      backend.send(input_room_id_text, input_name_text)
      stack.push(main_page)
    }
  }
}
