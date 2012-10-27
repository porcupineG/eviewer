import QtQuick 1.1

Rectangle  {
    id: timeline

    property real startSec;
    property real stopSec;

    gradient: Gradient {
        GradientStop { position: 0.5; color: "gray" }
        GradientStop { position: 0.7; color: "lightgrey" }
        GradientStop { position: 0.8; color: "lightgrey" }
        GradientStop { position: 1.0; color: "gray" }
    }

    Description {
        anchors.fill: timeline
    }

}
