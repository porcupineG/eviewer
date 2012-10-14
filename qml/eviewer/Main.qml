import QtQuick 1.1

import "timeline"

Item  {
    id:     main
    width:  800
    height: 400

    Timeline {
        id: timeline
        anchors.top:    main.top
        anchors.left:   main.left
        anchors.right:  main.right
        height: 30
    }

    MouseArea {
        anchors.fill: main
        onClicked: timeline.start += 40


    }


}
