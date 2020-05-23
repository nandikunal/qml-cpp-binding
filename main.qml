import QtQuick 2.1
import QtQuick.Window 2.1

Window {
    property string currentTime: "Time is not Set"
    property alias startButtonText: btnStart.buttonText
    property alias stopButtonText: btnStop.buttonText

    function myQmlFunction(timeDate) {
        currentTime = timeDate;
    }

    // Connect to CPP Class object 'TimeUpdate'
    Connections {
        target: TimeUpdate
        // recieve signal emitted from cpp
        onCurrentTime: {
            myQmlFunction(currentDateTime)
        }

        onTimerStarted: {
            startButtonText = "Started"
            stopButtonText = "Stop"
        }

        onTimerStopped: {
            stopButtonText = "Stopped"
            startButtonText = "Start"
        }
    }

    visible: true
    width: 640
    height: 480
    title: qsTr("Hello World")

    Column {
        id: columnLayout
        anchors.centerIn: parent
        spacing: 50

        Text {
            id: textStatus
            objectName: "TextStatus"
            text: currentTime
            font.bold: true
            font.pointSize: 20
            anchors.horizontalCenter: parent.horizontalCenter
        }

        Row {
            spacing: 50
            StatusButton {
                id: btnStart
                objectName: "ButtonStart"
                buttonText: "Start"

                // define signal name
                signal startTimer()
                MouseArea {
                    anchors.fill: btnStart
                    onClicked: {
                        // emit qml signal
                        btnStart.startTimer()
                    }
                }
            }


            StatusButton {
                id: btnStop
                objectName: "ButtonStop"
                buttonText: "Stop"

                signal stopTimer()
                MouseArea {
                    anchors.fill: btnStop
                    onClicked: {
                        btnStop.stopTimer()
                    }
                }
            }
        }
    }
}
