import QtQuick 1.1

import "Functions.js" as Functions

Item {
    property real start: 0
    property real stop: 100

    id: description
    width: 800
    height: 400

    Repeater {
        model: Functions.getBigRepetitions(description.start, description.stop, description.width)
        Rectangle {
            width:  2
            height: description.height / 2
            y: description.height / 2
            color: "black"
            x: start + Functions.getBigStep(description.start, description.stop, description.width) * index
        }
    }

    Repeater {
        model: Functions.getBigRepetitions(description.start, description.stop, description.width)
        Text {
            x: Functions.getBigStep(description.start, description.stop, description.width) * index - paintedWidth / 2
            text: qsTr("" + index / Functions.getBigStepSec(description.start, description.stop, description.width) + "ms")
        }
    }

    Repeater {
        model: Functions.getSmallRepetitions(description.start, description.stop, description.width)
        Rectangle {
            width:  1
            height: description.height / 4
            y: description.height / 2
            color: "black"
            x: start + Functions.getSmallStep(description.start, description.stop, description.width) * index
        }
    }

}
