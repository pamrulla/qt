import QtQuick 2.12

Rectangle {
    id: root
    width: 200
    height: 200
    color: "#4A4A4A"

    Image {
        id: triangle
        source: "assets/triangle_red.png"
        x: (parent.width - width) / 2
        y: 40
    }

    Text {
        y: triangle.y + triangle.height +  20
        width: root.width
        color: 'white'
        horizontalAlignment: Text.AlignHCenter
        text: "Triangle"
    }
}
