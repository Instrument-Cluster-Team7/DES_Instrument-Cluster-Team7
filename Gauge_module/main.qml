import QtQuick 2.12
import QtQuick.Controls 2.15
import QtQuick.Window 2.12

ApplicationWindow  {
    id: gauge
    visible: true
    width: 1280
    height: 400
    color: "#28282c"
    title: qsTr("Gauge_hanbin")

    property int dial_Size: height * 0.9
    property int needleLength: height * 0.3
    property int speedValue: 0

    Dial{
        id: dial
        anchors.verticalCenter: parent.verticalCenter
        anchors.left: parent.left
        anchors.leftMargin: height * 0.2

        dialSize: gauge.dial_Size
    }

    Needle{
        id: needle
        anchors.horizontalCenter: dial.horizontalCenter
        anchors.bottom: dial.bottom
        anchors.bottomMargin: dial.height / 2
        length: needleLength
        angle: (Receiver.speedKmh + 240) * 100 //(Receiver.speedKmh - 240) * 10

        Connections{
            target: Receiver
            onSpeedChanged: needle.angle = (Receiver.speedKmh + 240) * 100//(Receiver.speedKmh - 240) * 10
        }
    }

    Text {
        id: speedText
        text: Receiver.speedKmh.toFixed(2)//(speedProvider.speedValue + 240) / 2 + " km/h"
        anchors.horizontalCenter: dial.horizontalCenter
        anchors.bottom: dial.bottom
        anchors.bottomMargin: dial.height * 0.2
        color: "white"
        font.bold: true
        font.pixelSize: 30
    }

    Text{
        id: timeDisplay
        text: Clock.currentTime
        anchors.horizontalCenter: parent.horizontalCenter
        anchors.top: parent.top
        anchors.topMargin: parent.height * 0.2
        font.pixelSize: 50
        color: "#00b890"
    }

    Connections{
        target: Clock
        onTimeChanged: timeDisplay.text = Clock.currentTime
    }
}
