import QtQuick 2.12
import QtQuick.Window 2.12

Rectangle {
    width: 400
    height: 200
    color: 'darkgray'
    Rectangle {
        id: box
        width: 48
        height: 48
        x: 8
        y: 8
    }
    focus: true
    Keys.onLeftPressed: box.x -= 8
    Keys.onRightPressed: box.x += 8
    Keys.onUpPressed: box.y -= 8
    Keys.onDownPressed: box.y += 8
    Keys.onPressed: {
        switch(event.key) {
        case Qt.Key_Plus:
            box.scale += 0.2
            break
        case Qt.Key_Minus:
            box.scale -= 0.2
            break
        case Qt.Key_R:
            box.rotation += 1
            break
        case Qt.Key_E:
            box.rotation -= 1
            break
        }
    }
}
