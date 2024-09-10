import QtQuick 2.0

Item {
    id: speedTextComponent
    property int currentSpeed: 0
    property int targetSpeed: 0

    Text{
        id: speedText
        text: Math.round((currentSpeed + 240) / 2) + "km/h"
        font.pixelSize: 30
        color: "white"
        anchors.centerIn: parent
        font.bold: true

        NumberAnimation{
            id: speedAnimation
            target: speedTextComponent
            property: "currentSpeed"
            to: targetSpeed
            duration: 800
            easing.type: Easing.InOutQuad
        }
    }

    Connections{
        target: speedProvider
        onSpeedChanged: {
            speedTextComponent.targetSpeed = speedProvider.speedValue
            speedAnimation.start()
        }
    }

}
