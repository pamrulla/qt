import QtQuick 2.12

Item {
    width: 800
    height: 800

    Flow {
        anchors.fill: parent
        anchors.margins: 20
        spacing: 10

        MyBox {
            id: rowPositioning
            width: 48 * 3
            height: 48 * 1
            Row {
                MyBox{
                    color: 'red'
                }
                MyBox{
                    color: 'green'
                }
                MyBox{
                    color: 'blue'
                }
            }
        }

        MyBox {
            id: columnPositioning
            width: 48 * 1
            height: 48 * 3
            Column {
                MyBox{
                    color: 'red'
                }
                MyBox{
                    color: 'green'
                }
                MyBox{
                    color: 'blue'
                }
            }
        }

        MyBox {
            id: rowPositioningRightToLeft
            width: 48 * 3
            height: 48 * 1
            Row {
                layoutDirection: Qt.RightToLeft
                MyBox{
                    color: 'red'
                }
                MyBox{
                    color: 'green'
                }
                MyBox{
                    color: 'blue'
                }
            }
        }

        MyBox {
            id: gridPositioning
            width: 48 * 3
            height: 48 * 3
            Grid {
                rows: 2
                columns: 2
                spacing: 8
                anchors.centerIn: parent
                MyBox{
                    color: 'red'
                }
                MyBox{
                    color: 'green'
                }
                MyBox{
                    color: 'blue'
                }
            }
        }

        MyBox {
            id: repeater
            width: 252
            height: 252
            property variant colorArray: ["#00bde3", "#67c111", "#ea7025"]

            Grid{
                anchors.fill: parent
                anchors.margins: 8
                spacing: 4
                Repeater {
                    model: 16
                    Rectangle {
                        width: 56; height: 56
                        property int colorIndex: Math.floor(Math.random()*3)
                        color: repeater.colorArray[colorIndex]
                        border.color: Qt.lighter(color)
                        Text {
                            anchors.centerIn: parent
                            color: "#f0f0f0"
                            text: "Cell " + index
                        }
                    }
                }
            }
        }
    }
}
