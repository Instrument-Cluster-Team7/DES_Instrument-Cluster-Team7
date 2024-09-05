import QtQuick 2.5
import QtQuick.Controls 1.4

ApplicationWindow {
    visible: true
    width: 400
    height: 400
    title: "Speedometer"

    Rectangle {
        id: speedometer
        width: 300
        height: 300
        anchors.centerIn: parent
        color: "black"
        radius: 150

        // Draw the speedometer dial
        Canvas {
            id: dial
            anchors.fill: parent
            onPaint: {
                var ctx = dial.getContext("2d");
                ctx.clearRect(0, 0, dial.width, dial.height);

                // Draw outer circle
                ctx.beginPath();
                ctx.arc(dial.width / 2, dial.height / 2, dial.width / 2 - 10, 0, Math.PI * 2);
                ctx.lineWidth = 5;
                ctx.strokeStyle = "white";
                ctx.stroke();

                // Draw tick marks for speed increments
                ctx.lineWidth = 3;
                for (var i = 5; i < 14; i++) {
                    var angle = (Math.PI / 6) * i;
                    var x1 = dial.width / 2 + Math.cos(angle) * (dial.width / 2 - 20);
                    var y1 = dial.height / 2 + Math.sin(angle) * (dial.height / 2 - 20);
                    var x2 = dial.width / 2 + Math.cos(angle) * (dial.width / 2 - 40);
                    var y2 = dial.height / 2 + Math.sin(angle) * (dial.height / 2 - 40);
                    ctx.beginPath();
                    ctx.moveTo(x1, y1);
                    ctx.lineTo(x2, y2);
                    ctx.strokeStyle = "white";
                    ctx.stroke();
                }
            }
        }

        // Needle
        Rectangle {
            id: needle
            width: 5
            height: 90
            color: "red"
            anchors.horizontalCenter: parent.horizontalCenter
            anchors.bottom: parent.bottom
            anchors.bottomMargin: parent.height / 2
            transformOrigin: Item.Bottom
            rotation: speedValue / 2  // Scale for the needle angle
        }

        // Speed Display
        Text {
            id: speedText
            text: (speedValue + 250) * 2 / 5 + " km/h"
            anchors.horizontalCenter: parent.horizontalCenter
            anchors.bottom: parent.bottom
            anchors.bottomMargin: 60
            color: "white"
            font.bold: true
            font.pixelSize: 24
        }
    }

    // Dynamic speed value
    property int speedValue: -240

    // Timer to simulate speed changes
    Timer {
        interval: 500
        running: true
        repeat: true
        onTriggered: {
            // Simulating speed change (you will bind this to actual vehicle data)
            if(speedValue > 200){
                speedValue = -240;
            }
            else{
                speedValue += 480/9;
            }
            //speedValue = (-200 + speedValue + 10) % 300
            //speedValue = (speedValue + 10) % 241;
        }
    }
}
