import QtQuick 2.9
import QtQuick.Window 2.2

Window {
    visible: true
    width: 960
    height: 540
    title: qsTr("基本的QML元素")
    Text {
         text: "The quick brown fox"
         color: "#303030"
         font.family: "Ubuntu"
         font.pixelSize: 28
     }
    Image {
        x: 0; y: 30
        // width: 72
        // height: 72
        source: "assets/triangle_red.png"
    }
    Image {
        x: 72; y:30
        // width: 72
        height: 72/2
        source: "assets/triangle_red.png"
        fillMode: Image.PreserveAspectCrop
        clip: true
    }
    Image {
        x: 72+72; y:30
        // width: 72
        height: 72/3
        source: "assets/triangle_red.png"
        fillMode: Image.PreserveAspectCrop
        clip: true
    }

    Rectangle {
        id: rect1
        x: 0; y: 30+72
        width: 96; height: 96
        color: "red"
        MouseArea {
            id: area
            width: parent.width
            height: parent.height
            onClicked: rect2.visible = !rect2.visible
        }
    }

    Rectangle {
        id: rect2
        x: 100+100; y: 30+72
        width: 96; height: 96
        color: "blue"
        border.color: "purple"
        border.width: 4
        radius: 50
    }


    Rectangle {
//        id: rect2
        x: 0; y: 30+72+96
        width: 100; height: 100
        border.color: "blue"
        color:"red"
        border.width: 4
        radius: 1
    }
    Rectangle {
//        id: rect2
        x: 100; y: 30+72+96
        width: 100; height: 100
        border.color: "red"
        color: "orange"
        border.width: 4
        radius: 2
    }
    Rectangle {
//        id: rect2
        x: 200; y: 30+72+96
        width: 100; height: 100
        border.color: "orange"
        color:"yellow"
        border.width: 4
        radius: 4
    }
    Rectangle {
//        id: rect2
        x: 300; y: 30+72+96
        width: 100; height: 100
        border.color: "orange"
        color:"green"
        border.width: 4
        radius: 8
    }
    Rectangle {
//        id: rect2
        x: 400; y: 30+72+96
        width: 100; height: 100
        border.color: "green"
        color:"cyan"
        border.width: 4
        radius: 16
    }
    Rectangle {
//        id: rect2
        x: 500; y: 30+72+96
        width: 100; height: 100
        border.color: "cyan"
        color:"blue"
        border.width: 4
        radius: 32
    }
    Rectangle {
//        id: rect2
        x: 600; y: 30+72+96
        width: 100; height: 100
        border.color: "blue"
        color: "purple"
        border.width: 4
        radius: 64
    }
    Rectangle {
//        id: rect2
        x: 700; y: 30+72+96
        width: 100; height: 100
        border.color: "purple"
        color:"black"
        border.width: 4
        radius: 008
    }
}
