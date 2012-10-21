import QtQuick 1.1

import "../core.js" as Core

Item {

    id: description
    width: 800
    height: 400

    Repeater {
        model: Core.getBigRepetitions(description.start, description.stop, description.width)
        Rectangle {
            width:  2
            height: description.height / 2
            y: description.height / 2
            color: "black"
            x: Core.getBigStep(description.start, description.stop, description.width) * index
        }
    }

    Repeater {
        model: Core.getBigRepetitions(description.start, description.stop, description.width)
        Text {
            x: Core.getBigStep(description.start, description.stop, description.width) * index - paintedWidth / 2
            text: qsTr("" + index / Core.getBigStepSec(description.start, description.stop, description.width) + "ms")
        }
    }

    Repeater {
        model: Core.getSmallRepetitions(description.start, description.stop, description.width)
        Rectangle {
            width:  1
            height: description.height / 4
            y: description.height / 2
            color: "black"
            x: Core.getSmallStep(description.start, description.stop, description.width) * index
        }
    }

}
