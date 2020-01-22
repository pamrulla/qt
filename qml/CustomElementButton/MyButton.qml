import QtQuick 2.0

Item {
    id: root
    width: 112
    height: 26

    property alias text: label.text
    signal clicked

    Rectangle {
        anchors.fill: parent
        color: 'lightsteelblue'
        border.color: 'slategray'
        radius: 10
    }

    Text {
        id: label
        anchors.centerIn: parent
        text: "Button"
    }

    MouseArea {
        anchors.fill: parent
        onClicked: {
            root.clicked()
        }
    }
}
