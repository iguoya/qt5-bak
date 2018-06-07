import QtQuick 2.9
import QtQuick.Window 2.2

Window {
    visible: true
    width: 512
    height: 320
    title: qsTr("Meet Qt5")
    Image {
        id: root
        source: "images/background.png"
        Image {
            id: pole
            anchors.horizontalCenter: parent.horizontalCenter
            anchors.bottom: parent.bottom
            source: "images/pole.png"
        }
        Image {
            id: wheel
            anchors.centerIn: parent
            source: "images/pinwheel.png"
            Behavior on rotation {
                NumberAnimation {
                    duration: 1000*100*1
                }
            }
        }
        MouseArea {
            anchors.fill: parent
            onClicked: wheel.rotation += 360*100
        }
    }
}
