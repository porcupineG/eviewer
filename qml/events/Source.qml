import QtQuick 1.1

Rectangle {
    id: source
    width: 100000
    height: 50
    border.color: 'black'
    color: "red"

    Binding {
        target: source.border
        property: 'width'
        value: 2
        when: ma.containsMouse
    }

    Binding {
        target: source.border
        property: 'width'
        value: 0
        when: !ma.containsMouse
    }

    MouseArea {
        id: ma
        anchors.fill: source
        hoverEnabled: true

//        onEntered: {
//            source.border.width = 2
//        }
//        onExited: {
//            source.border.width = 0
//        }
    }
}
