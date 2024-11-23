import QtQuick
import QtQuick.Controls
import QtQuick.Layouts

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
        onRegistrate: stack.push(main_page)
    }
}
