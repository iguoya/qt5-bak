import QtQuick 2.0

Rectangle {
    width: 96; height: input.height + 28
    color: "indianred"
    border.color: "gray"

    property alias text: input.text
    property alias input: input
//    spacing:10
    TextInput {
        id: input
        anchors.fill: parent
        anchors.margins: 4
        focus: false
    }
}
