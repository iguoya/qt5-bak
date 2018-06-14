import QtQuick 2.9
import QtQuick.Window 2.2

Window {
    visible: true
    width: 960
    height: 540
    title: qsTr("流动布局")


    Image {
        id: root
        source: "assets/background.png"


        property int padding: 40
        property int duration: 400
        property bool running: false

        Image {
            id: box
            x: root.padding;
            y: (root.height-height)/2
            source: "assets/box_green.png"

            NumberAnimation on x {
                to: root.width - box.width - root.padding
                duration: root.duration
                running: root.running
            }
            RotationAnimation on rotation {
                to: 360
                duration: root.duration
                running: root.running
            }
        }

        MouseArea {
            anchors.fill: parent
            onClicked: root.running = true
        }
    }

    ClickableImageV2 {
        id: greenBox
        y: 500
        x: 40;
        source: "assets/box_green.png"
        text: "animation on property"
        NumberAnimation on y {
            to: 70; duration: 3000
        }
    }
    ClickableImageV2 {
        id: blueBox
        x: 200; y: 480
        source: "assets/box_blue.png"
        text: "behavior on property"
        Behavior on y {
            NumberAnimation { duration: 4000 }
        }

        onClicked: y = 40
        // random y on each click
        //        onClicked: y = 40+Math.random()*(205-40)
    }

    ClickableImageV2 {
        id: redBox
        x: 400; y: 480
        source: "assets/box_red.png"
        onClicked: anim.start()
//        onClicked: anim.restart()

        text: "standalone animation"

        NumberAnimation {
            id: anim
            target: redBox
            properties: "y"
            to: 40
            duration: 2000
        }
    }

}
