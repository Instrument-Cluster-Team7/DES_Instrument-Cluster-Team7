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

    /*///////////////////////////////////////////////////////// RPM_component */
    // initial values
    //    property real speed: 0
    //    property real rpm: 0.0
    //    property real tire_circumference: 0.174 // 2.0
    //    // meter - piracer wheel base is about 174.1mm
    //    property real gear_ratio: 2.0 // 4.0

    //    function calculateRPM(speed){
    //        return (speed * 1000) / (tire_circumference * gear_ratio);
    //    }

    //    Timer{
    //        id: test_rpm_timer
    //        interval: 1000
    //        repeat: true
    //        running: true
    //        onTriggered: {
    //            speed = Math.random();
    //            rpm = calculateRPM(speed);
    //            console.log("Speed: " + speed + " km/h, RPM: " + rpm);
    //        }
    //    }

    Rectangle {
        id: rpmgauge
        x: 848
        y: 0
        width: 400
        height: 400
        anchors.right: parent.right
        anchors.rightMargin: 32
        color: "#28282c"

//        Rectangle {
//            id: needle
//            width: 5
//            height: 90
//            color: "#a2f2d9"
//            anchors.horizontalCenter: parent.horizontalCenter
//            anchors.bottom: parent.bottom
//            anchors.bottomMargin: parent.height / 2
//            transformOrigin: Item.Bottom

//            rotation: rpm_speedometer.startAngle - 40 + ((rpm_speedometer.speed - rpm_speedometer.lowestRange) * rpm_speedometer.alignAngle / (rpm_speedometer.highestRange - rpm_speedometer.lowestRange))
//            // rotation: ((rpm_speedometer.speed - rpm_speedometer.lowestRange)/(rpm_speedometer.highestRange - rpm_speedometer.lowestRange)) * (0 - rpm_speedometer.alignAngle)
//            // rotation: ((rpm_speedometer.speed - rpm_speedometer.lowestRange) / (rpm_speedometer.highestRange - rpm_speedometer.lowestRange)) * rpm_speedometer.alignAngle - rpm_speedometer.startAngle
//            // valueToAngle = ((m_Speed - m_LowestRange)/(m_HighestRange - m_LowestRange)) * spanAngle;
//        }

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
            source: "Ellipse 1.svg"
            fillMode: Image.PreserveAspectFit
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
            fillMode: Image.PreserveAspectFit
            source: "battery.png"
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
        anchors.verticalCenterOffset: 158
        anchors.horizontalCenterOffset: 0 // "Running Rate: " + elapsedTime + " seconds"
        anchors.centerIn: parent
        font.pixelSize: 13
        color: "white"
    }
}
