import QtQuick 2.9
import QtQuick.Window 2.2

Window {
    visible: true
    width: 640
    height: 480
    title: qsTr("组件演示")
    Button { // our Button component
        id: button
        text: "Start"
        property bool flag  : true
        onClicked: {
            if(flag) {
                status.text = "I Received !"
                text = "Return"
                flag = false
            } else {
                status.text =  "waiting ..."
                text = "Start"
                flag = true
            }
        }
        Text { // text changes when button was clicked
            id: status
            x: 200
            width: 120
            text: "waiting ..."
            horizontalAlignment: Text.AlignHCenter
        }
    }

    Item {

        y:30
        // set width based on given background
        width: bg.width
        height: bg.height

        Image { // nice background image
            id: bg
            source: "assets/background.png"
        }

        MouseArea {
            id: backgroundClicker
            // needs to be before the images as order matters
            // otherwise this mousearea would be before the other elements
            // and consume the mouse events
            anchors.fill: parent
            onClicked: {
                // reset our little scene
                circle.x = 84
                box.rotation = 0
                triangle.rotation = 0
                triangle.scale = 1.0
            }
        }

        ClickableImage {
            id: circle
            y: 100
            source: "assets/circle_blue.png"
            antialiasing: true
            onClicked: {
                // increase the x-position on click
                x += 50
            }
        }

        ClickableImage {
            id: box1
            x: 164; y: 68
            source: "assets/box_green@2x.png"
            antialiasing: true
            onClicked: {
                // increase the rotation on click
                rotation += 45
            }
        }
        ClickableImage {
            id: box2
            x: 264; y: 68
            source: "assets/box_green@2x.png"
            antialiasing: true
            onClicked: {
                // increase the rotation on click
                rotation += 45
            }
        }

        ClickableImage {
            id: triangle
            x: 348; y: 68
            source: "assets/triangle_red@2x.png"
            antialiasing: true
            onClicked: {
                // several transformations
                rotation += 45
                scale += 0.5
            }
        }

        function _test_transformed() {
            circle.x += 20
            box.rotation = 15
            triangle.scale = 1.2
            triangle.rotation = -15
        }

        function _test_overlap() {
            circle.x += 40
            box.rotation = 15
            triangle.scale = 2.0
            triangle.rotation = 45
        }

    }

}
