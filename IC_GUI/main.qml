import QtQuick 2.12
import QtQuick.Window 2.12
import com.DESInstrumentClusterTeam7.speedometer 1.0
import QtQuick.Controls 1.2
import QtQuick.Layouts 1.1

ApplicationWindow  {
    id: gauge
    visible: true
    width: 1280
    height: 400
    color: "#28282c"
    title: qsTr("Instrument Cluster")

    property int dial_Size: height * 0.9
    property int needleLength: height * 0.3
    property int speedValue: 0

    Dial{
        id: dial
        anchors.verticalCenter: parent.verticalCenter
        anchors.left: parent.left
        anchors.leftMargin: height * 0.2

        property int dialSize: gauge.dial_Size
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

    SpeedText{
        id: speedText
        anchors.horizontalCenter: dial.horizontalCenter
        anchors.bottom: dial.bottom
        anchors.bottomMargin: dial.height * 0.2
    }

    Text{
        id: timeDisplay
        text: Clock.currentTime
        anchors.horizontalCenterOffset: -54
        anchors.topMargin: 70
        anchors.horizontalCenter: parent.horizontalCenter
        anchors.top: parent.top
        font.pixelSize: 30
        color: "#00b890"
    }

    Connections{
        target: Clock
        onTimeChanged: timeDisplay.text = Clock.currentTime
    }

    /*///////////////////////////////////////////////////////// RPM_component */
    Rectangle {
        id: rpmgauge
        x: 848
        y: 0
        width: 400
        height: 400
        anchors.right: parent.right
        anchors.rightMargin: 32
        color: "#28282c"

        Speedometer {
            id: rpm_speedometer
            objectName: "RPM_Gauge"
            anchors.horizontalCenter: parent.horizontalCenter
            //            anchors.bottom: parent.bottom
            //            anchors.bottomMargin: -10
            anchors.centerIn: parent
            width: speedometerSize
            height: speedometerSize
            startAngle: startAngle
            alignAngle: alignAngle
            lowestRange: lowestRange
            highestRange: highestRange
            speed: speed // rpm
            arcWidth: arcWidth
            outerColor: outerColor
            innerColor: innerColor
            textColor: textColor
            backgroundColor: backgroundColor
        }

        Text {
            id: rpm_speedometer_value
            anchors.centerIn: parent
            anchors.bottom: parent.bottom
            font.pixelSize: 55 // 30
            color: "white"

            text: Math.floor(rpm_speedometer.speed) // Math.floor(Math.random() * 101);
        }

        Text {
            id: rpm_text
            text: qsTr("RPM")
            anchors.verticalCenterOffset: 92
            anchors.horizontalCenterOffset: 0
            anchors.bottomMargin: -92
            font.pixelSize: 30
            color: "white"
            anchors.centerIn: parent
            anchors.bottom: parent.bottom
        }

        Image {
            id: out_circleline
            x: 22
            y: 19
            width: 360
            height: 360
            anchors.centerIn: parent
            fillMode: Image.PreserveAspectFit
            source: "Ellipse 1.svg"
        }

        Image {
            id: inner_circleline
            x: 58
            y: 68
            width: 220
            height: 220
            anchors.verticalCenterOffset: -9
            anchors.horizontalCenterOffset: 0
            anchors.centerIn: parent
            fillMode: Image.PreserveAspectFit
            source: "ring.svg"
        }
    }


    /*///////////////////////////////////////////////////////// battery_component */
    property real battery_value: 0.5


    Rectangle {
        id: battery
        color: "transparent"
        anchors.verticalCenterOffset: -119
        anchors.horizontalCenterOffset: 76
        anchors.centerIn: parent
        width: battery_img.width // 169
        height: battery_img.height // 85

        Rectangle {
            id: battery_percentage
            anchors.top: battery_img.top
            anchors.topMargin: 8
            //            anchors.left: battery_img.left
            //            anchors.leftMargin: 4
            x: 4
            y: 0
            width: (battery_value * (battery_img.width - 2 * 4)) // battery_value * battery_img.width
            height: battery_img.height - 14
            color: "#00b890"
        }

        Image {
            id: battery_img
            width : 80
            height: 40
            anchors.fill: parent
            source: "battery.png"
            fillMode: Image.PreserveAspectFit
        }

        Text {
            id: battery_text
            anchors.centerIn: parent
            anchors.bottom: parent.bottom
            font.pixelSize: 18 // 30
            color: "white"
            text: Math.floor(battery_value * 101) + "%" // Math.floor(Math.random() * 101);

            anchors.verticalCenterOffset: 36
            anchors.horizontalCenterOffset: 0
            anchors.bottomMargin: -36
        }
    }

    Timer {
        id: test_battery_timer
        interval: 1000
        repeat: true
        running: true
        onTriggered: {
            battery_value = Math.random();
        }
    }


    /*///////////////////////////////////////////////////////// runningRate_component */
    function timeformat(elapsedTime){
        var minutes = Math.floor(elapsedTime / 60);
        var secs = elapsedTime % 60;

        var minutes_format = minutes < 10 ? "0" + minutes : minutes;
        var secs_format = secs < 10 ? "0" + secs : secs;

        return minutes_format + ":" + secs_format;
    }

    Text {
        id: running_rate
        text: "Running Rate: " + timeformat(elapsedTime)
        anchors.verticalCenterOffset: 159
        anchors.horizontalCenterOffset: 0 // "Running Rate: " + elapsedTime + " seconds"
        anchors.centerIn: parent
        font.pixelSize: 13
        color: "white"
    }


    /*///////////////////////////////////////////////////////// background */
    Image {
        id: left_load
        x: 486
        y: 134
        width: 135
        height: 266
        source: "Vector 1.svg"
        fillMode: Image.PreserveAspectFit
    }

    Image {
        id: right_load
        x: 665
        y: 134
        width: 135
        height: 266
        source: "Vector 2.svg"
        fillMode: Image.PreserveAspectFit
    }
}
