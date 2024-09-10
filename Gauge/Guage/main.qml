import QtQuick 2.12
import QtQuick.Window 2.12
import com.ulasdikme.speedometer 1.0
import QtQuick.Controls 2.15
import QtQuick.Layouts 1.1

Window {
    visible: true
    width: 1280 //640
    height: 400 //480
    color: "#000000"
    title: qsTr("Test Gauge")

//    Image {
//        id: image
//        x: 417
//        y: 14
//        width: 446
//        height: 373
//        source: "pngegg.png"
//        fillMode: Image.PreserveAspectFit
//    }

    Speedometer
    {
        objectName: "speedoMeter"
        anchors.horizontalCenter:  parent.horizontalCenter
        anchors.bottom: parent.bottom
        anchors.bottomMargin: -30
        width: speedometerSize
        height: speedometerSize
        startAngle: startAngle
        alignAngle: alignAngle
        lowestRange: lowestRange
//        highestRange: highestRange
        speed: speed
        arcWidth: arcWidth
        outerColor: outerColor
        innerColor: innerColor
        textColor: textColor
        backgroundColor: backgroundColor
    }

//    Text {
//        id: text
//        text: qsTr("text")
//    }
}
