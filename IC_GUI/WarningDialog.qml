import QtQuick 2.12
import QtQuick.Controls 2.12

Popup {
    id: warningDialog
    modal: true
    focus: true
    width: 200
    height: 100
    visible: false

    property string messageText: "Disconnected CAN Data"

    Rectangle {
        width: parent.width
        height: parent.height
        color: "lightgray"
        radius: 10

        Text {
            text: messageText
            anchors.centerIn: parent
            font.pixelSize: 18
            color: "black"
        }
    }

}
