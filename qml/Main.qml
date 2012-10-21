import QtQuick 1.1

import "timeline"
import "events"
import "core.js" as Core

Item  {
    id:     main
    width:  800
    height: 400

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
        height: Core.timelineHeight
    }

    Rectangle {
        id: sidebar
        anchors.left: main.left
        anchors.top: main.top
        anchors.bottom: main.bottom
        width: Core.sideBarWidth
        color: "orange"
    }

}
