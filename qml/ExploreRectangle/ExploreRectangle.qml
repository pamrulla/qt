import QtQuick 2.12

Item {
    id: root
    width: 300
    height: 400

    Rectangle {
        id: filledRect
        x: 12
        y: 12
        width: 76
        height: 76
        color: 'lightsteelblue'
    }

    Rectangle {
        id: onlyBorderedRect
        x: 112
        y: 12
        width: 76
        height: 76
        border {
            color: 'lightsteelblue'
            width: 8
        }
        /*
               OR
        border.width: 4
        border.color: 'lightsteelblue'
        */
        radius: 8
    }
    Rectangle {
        id: gradientRect
        x: 212
        y: 12
        width: 76
        height: 76
        border.color: 'slategray'
        gradient: Gradient{
            GradientStop { position: 0.0; color: 'lightsteelblue'}
            GradientStop { position: 1.0; color: 'slategray'}
        }
    }
}
