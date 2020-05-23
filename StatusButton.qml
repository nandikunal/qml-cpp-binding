import QtQuick 2.0

Rectangle {
    property alias buttonText: buttonText.text

    id: rectButton
    width: 150
    height: 50
    color: "light blue"
    border.color: "blue"
    border.width: 1

    Text {
        id: buttonText
        font.bold: true
        font.pointSize: 14
        anchors.centerIn: parent
    }

    MouseArea {
        anchors.fill: rectButton
    }
}
