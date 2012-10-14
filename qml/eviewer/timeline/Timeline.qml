import QtQuick 1.1

Rectangle  {
    property real start: 0
    property real stop:  100

    id: timeline

    gradient: Gradient {
        GradientStop { position: 0.5; color: "gray" }
        GradientStop { position: 0.7; color: "lightgrey" }
        GradientStop { position: 0.8; color: "lightgrey" }
        GradientStop { position: 1.0; color: "gray" }
    }

    Description {
        start: timeline.start
        stop: timeline.stop
        anchors.fill: timeline
    }


}
