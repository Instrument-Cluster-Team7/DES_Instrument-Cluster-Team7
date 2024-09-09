import QtQuick 2.12
import QtQuick.Window 2.12
import com.DESInstrumentClusterTeam7.speedometer 1.0
import QtQuick.Controls 1.2
import QtQuick.Layouts 1.1

Window {
    visible: true
    width: 1280
    height: 400
    color: "#28282c"
    title: qsTr("Instrument Cluster")

    property real speed: rpm_speedometer.speed
    property real battery_value: 0.5

    Rectangle {
        id: rpmgauge
        width: 400
        height: 400
        anchors.right: parent.right
        color: "#28282c"

        Rectangle {
            id: needle
            width: 5
            height: 90
            color: "#a2f2d9"
            anchors.horizontalCenter: parent.horizontalCenter
            anchors.bottom: parent.bottom
            anchors.bottomMargin: parent.height / 2
            transformOrigin: Item.Bottom

            rotation: rpm_speedometer.startAngle - 40+ ((rpm_speedometer.speed - rpm_speedometer.lowestRange) * rpm_speedometer.alignAngle / (rpm_speedometer.highestRange - rpm_speedometer.lowestRange))
        }

        Speedometer {
            id: rpm_speedometer
            objectName: "RPM_Gauge"
            anchors.horizontalCenter: parent.horizontalCenter
            anchors.bottom: parent.bottom
            anchors.bottomMargin: -10
            width: speedometerSize
            height: speedometerSize
            startAngle: startAngle
            alignAngle: alignAngle
            lowestRange: lowestRange
            speed: speed
            arcWidth: arcWidth
            outerColor: outerColor
            innerColor: innerColor
            textColor: textColor
            backgroundColor: backgroundColor
        }
    }

    Rectangle {
        id: battery
        color: "transparent"
        anchors.centerIn: parent
        width: 169
        height: 85

        Rectangle {
            id: battery_percentage
            x: 19
            y: 12
            width: battery_value * battery_img.width - 40
            height: battery_img.height - 20
            color: "#00b890"
//            anchors.left: parent.left
//            anchors.leftMargin: 15
//            anchors.top: parent.top
//            anchors.topMargin: 8
//            anchors.bottomMargin: 10
        }

        Image {
            id: battery_img
            anchors.fill: parent
            fillMode: Image.PreserveAspectFit
            source: "battery.png"
        }

        Text {
            id: battery_text
            anchors.centerIn: parent
            font.pixelSize: 30
            color: "white"
            text: Math.floor(battery_value * 100) + "%"
            // Math.floor(Math.random() * 101);
        }
    }

    Timer {
        interval: 1000
        repeat: true
        running: true
        onTriggered: {
            battery_value = Math.random();
        }
    }
}
