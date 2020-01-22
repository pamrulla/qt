import QtQuick 2.12
import QtQuick.Window 2.12

Item {
    id: root
    width: 300
    height: 300

    Text {
        id: simpleText
        x: 10
        y: 10
        text: "The quick brown fox"
        color: '#303030'
        font {
            family: 'Ubuntu'
            pixelSize: 28
        }
    }

    Text {
        id: longText
        width: 80
        height: 120
        x: 10
        y: simpleText.height + 10
        text: "A very long text"
        elide: Text.ElideRight
        style: Text.Sunken
        styleColor: '#303030'
        verticalAlignment: Text.AlignVCenter
        horizontalAlignment: Text.AlignHCenter
    }
}
