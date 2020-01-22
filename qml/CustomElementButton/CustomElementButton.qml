import QtQuick 2.12
import QtQuick.Window 2.12

Item {
    id: root
    width: 200
    height: 200

    MyButton {
        id: button
        x: 12
        y: 12
        text: "Start"
        onClicked: {
            status.text = "Button Clicked!"
        }
    }

    Text {
        id: status
        x: 12
        y: 76
        width: 116
        height: 26
        text: "Waiting..."
        horizontalAlignment: Text.AlignHCenter
    }
}
