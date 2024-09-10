import QtQuick 2.12

Item {
    id: needle_comp

    property int length: 120
    property int angle: 0

    width: 5
    height: length

    Rectangle{
        id: needle
        width: parent.width
        height: parent.height
        color: "#00b890";
        anchors.centerIn: parent
        transformOrigin: Item.Bottom
        rotation: angle

        Behavior on rotation{
            NumberAnimation{
                duration: 800
                easing.type: Easing.InOutQuad
            }
        }
    }
}
