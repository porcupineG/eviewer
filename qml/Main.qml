import QtQuick 1.1

import "timeline"
import "events"
import "core.js" as Core

Item  {
    id: main

    Events {
        anchors.top: timeline.bottom
        anchors.bottom: main.bottom
        anchors.left: sidebar.right
        anchors.right: main.right
    }

    Timeline {
        id: timeline
        anchors.top:    main.top
        anchors.left:   sidebar.right
        anchors.right:  main.right
        height:     Core.timelineHeight
        startSec: 0
        stopSec: 100
    }

    Rectangle {
        id: sidebar
        anchors.left: main.left
        anchors.top: main.top
        anchors.bottom: main.bottom
        width: Core.viewWidth
        color: "orange"
        Text {
            id: textId
            text: "" + Core.getWidth()
        }
    }

}
