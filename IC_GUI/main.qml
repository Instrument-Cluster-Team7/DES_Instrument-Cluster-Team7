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
        z: 2

        property int dialSize: gauge.dial_Size
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

    Image {
        id: image
        anchors.horizontalCenter: dial.horizontalCenter
        anchors.verticalCenter: dial.verticalCenter
        source: "Ellipse 1.svg"
        fillMode: Image.PreserveAspectFit
        z: 0
    }

    Image {
        id: image1
        anchors.horizontalCenter: dial.horizontalCenter
        anchors.verticalCenter: dial.verticalCenter
        width: 335
        height: 325
        source: "Ellipse 5.svg"
        fillMode: Image.PreserveAspectFit
    }//*/

    Needle{
        id: needle
        anchors.horizontalCenter: dial.horizontalCenter
        anchors.bottom: dial.bottom
        anchors.bottomMargin: dial.height / 2
        length: needleLength
        angle: (Receiver.speedKmh + 240) * 100

        Connections{
            target: Receiver
            onSpeedChanged: needle.angle = (Receiver.speedKmh + 240) * 100
        }
    }

    SpeedText{
        id: speedText
        anchors.horizontalCenter: dial.horizontalCenter
        anchors.verticalCenter: dial.verticalCenter
    }

    /*///////////////////////////////////////////////////////// battery_component */
    Rectangle {
        id: batterygauge
        x: 848
        y: 0
        width: 400
        height: 400
        anchors.right: parent.right
        anchors.rightMargin: 32
        color: "#28282c"

        Speedometer {
            id: battery_speedometer
            objectName: "Battery_Gauge"
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
            battery: battery // rpm
            arcWidth: arcWidth
            outerColor: outerColor
            innerColor: innerColor
            textColor: textColor
            backgroundColor: backgroundColor
        }

        Text {
            id: battery_speedometer_value
            anchors.centerIn: parent
            anchors.bottom: parent.bottom
            font.pixelSize: 55 // 30
            color: "white"

            text: battery_value + "%"
            //text: Math.floor(rpm_speedometer.speed) // Math.floor(Math.random() * 101);
        }

        Text {
            id: battery_text
            text: qsTr("Battery")
            anchors.verticalCenterOffset: 116
            anchors.horizontalCenterOffset: 0
            anchors.bottomMargin: -116
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
            source: "out_ring.png"
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
        anchors.verticalCenterOffset: 164
        anchors.horizontalCenterOffset: 0 // "Running Rate: " + elapsedTime + " seconds"
        anchors.centerIn: parent
        font.pixelSize: 13
        color: "white"
    }


    /*///////////////////////////////////////////////////////// background */
    // version 1
    //    Image {
    //        id: left_load
    //        x: 486
    //        y: 134
    //        width: 135
    //        height: 266
    //        source: "Vector 1.svg"
    //        fillMode: Image.PreserveAspectFit
    //    }

    //    Image {
    //        id: right_load
    //        x: 665
    //        y: 134
    //        width: 135
    //        height: 266
    //        source: "Vector 2.svg"
    //        fillMode: Image.PreserveAspectFit
    //    }

    // version 2
    Image {
        id: background
        x: 430 //430
        y: 157 //158
        fillMode: Image.PreserveAspectFit
        source:  "back_ground_bright.png" // "background_g.png"

        Image {
            id: highlight
            x: 0
            y: 0
            fillMode: Image.PreserveAspectFit
            source: "car-highlights.png"
        }
    }

    Image {
        id: top_bar
        x: 353
        y: 0
        width: 575
        height: 79
        fillMode: Image.PreserveAspectFit
        source: "Vector 70.svg"
    }

//    Image {
//        id: bottom_bar
//        x: 346
//        y: 400
//        width: 588
//        height: 84
//        transform: Scale {
//            yScale: -1
//        }
//        fillMode: Image.PreserveAspectFit
//        source: "Vector 70.svg"
//    }
}
