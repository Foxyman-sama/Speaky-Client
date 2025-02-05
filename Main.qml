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

  Component {
    id: main_page
    MainPage {}
  }

  RegistrationForm {
    id: registration_form
    onRegistrate: {
      network.register_on_server(input_room_id_text, input_name_text)
    }
  }

  Connections {
    target: network

    function onSuccesfulRegistrationEmitted() {
      console.log("Success")
      stack.push(main_page)
    }

    function onFailureRegistrationEmitted() {
      console.log("Failure")
    }

    function onNameTakenEmitted() {
      console.log("Name Taken")
      registration_form.input_name_text = "NAME TAKEN"
    }
  }
}
