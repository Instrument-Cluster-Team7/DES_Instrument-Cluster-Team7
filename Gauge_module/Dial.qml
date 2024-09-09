import QtQuick 2.0

Item {
    id: bg_dial

    property int dialSize: 300

    width: dialSize
    height: dialSize

    Canvas {
        anchors.fill: parent
        onPaint: {
            var ctx = getContext("2d");
            ctx.clearRect(0, 0, width, height);

            ctx.beginPath();
            ctx.arc(bg_dial.dialSize/2, bg_dial.dialSize/2, bg_dial.width / 2 - 10, 0, Math.PI * 2);
            ctx.lineWidth = 5;
            ctx.strokeStyle = "#00b890";
            ctx.stroke();

            ctx.lineWidth = 3;
            for(var i = 5; i < 14; i++){
                var angle = (Math.PI / 6) * i;
                var x1 = bg_dial.width / 2 + Math.cos(angle) * (bg_dial.width / 2 - 20);
                var y1 = bg_dial.height / 2 + Math.sin(angle) * (bg_dial.height / 2 - 20);
                var x2 = bg_dial.width / 2 + Math.cos(angle) * (bg_dial.width / 2 - 40);
                var y2 = bg_dial.height / 2 + Math.sin(angle) * (bg_dial.height / 2 - 40);

                ctx.beginPath();
                ctx.moveTo(x1,y1);
                ctx.lineTo(x2,y2);
                ctx.strokeStyle = "#00b890";
                ctx.stroke();
            }
        }
    }

}
