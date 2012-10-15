import QtQuick 1.1

Rectangle {
    color: "lightsteelblue"

    ListModel {
        id: listModel

        ListElement {
            name: "Apple"
            colour: "blue"
        }

        ListElement {
            name: "Orange"
            colour: "green"
        }

        ListElement {
            name: "Banana"
            colour: "red"
        }
    }

    Flickable {
        anchors.fill: parent
        contentWidth: 10000
        ListView {
             anchors.fill: parent
             model: listModel
             spacing: 10
             delegate: Row {
                 Rectangle {
                    height: 100
                    width: 10000
                    color: colour

                    Text {
                        text: "123456789"
                    }

                 }
             }
        }
    }
}
