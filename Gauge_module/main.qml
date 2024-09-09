import QtQuick 2.12
import QtQuick.Controls 2.0
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
        angle: speedProvider.speedValue / 2//* 1.5  //speedValue / 2

        Connections{
            target: speedProvider
            onSpeedChanged: needle.angle = speedProvider.speedValue / 2//* 1.5
        }
    }

    Text {
        id: speedText
        text: (speedProvider.speedValue + 240) / 2 + " km/h"
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