import QtQuick 2.9
import QtQuick.Window 2.2

Window {
    visible: true
    width: 640
    height: 480
    title: qsTr("文本框修饰")

    Rectangle {
        width: 200
        height: 80
        color: "lavender"

        TLineEditV1 {
            id: input1
            x: 8; y: 8
            width: 96; height: 30
            focus: false
            text: "Text Input 1"
        }

        TLineEditV2 {
            id: input2
            x: 8; y: 36
            width: 96; height: 30
            text: "Text Input 2"
        }

        Rectangle {
            y: 80
            width: 136
            height: 120
            color: "gold"

            TTextEdit {
                id: input
                x: 8; y: 8
                width: 120; height: 104
                focus: false
                text: "Text Edit"
            }
        }

        Item {
            y:200
            width: 400; height: 200

            GreenSquare {
                id: square
                x: 8; y: 8
            }
            focus: true
            Keys.onLeftPressed: square.x -= 8
            Keys.onRightPressed: square.x += 8
            Keys.onUpPressed: square.y -= 8
            Keys.onDownPressed: square.y += 8
            Keys.onPressed: {
                switch(event.key) {
                case Qt.Key_Plus:
                    square.scale += 0.2
                    break;
                case Qt.Key_Minus:
                    square.scale -= 0.2
                    break;
                }

            }
        }


    }



    //    Rectangle {
    //        y: r1.height+30
    //        width: 96; height: input.height + 8
    //        color: "lightsteelblue"
    //        border.color: "gray"

    //        property alias text: input.text
    //        property alias input: input

    //        TextInput {
    //            id: input
    //            anchors.fill: parent
    //            anchors.margins: 4
    //            focus: true
    //        }
    //    }
}
