import QtQuick 2.9
import QtQuick.Controls 2.2
import QtQuick.Layouts 1.0

Page {
    id: page
    width: 640
    height: 440
    title: "Settings"

    GridLayout {
        y: 110
        anchors.right: parent.right
        anchors.left: parent.left
        anchors.leftMargin: 0
        anchors.verticalCenter: parent.verticalCenter
        Layout.alignment: Qt.AlignHCenter | Qt.AlignVCenter
        rows: 5
        columns: 2

        Label {
            id: label
            text: qsTr("API Link")
        }

        TextField {
            id: linkText
            text: config.link
            placeholderText: ""
            Layout.fillWidth: true
        }

        Label {
            id: label1
            text: qsTr("Application ID")
        }

        TextField {
            id: appKeyText
            text: config.appKey
            Layout.fillWidth: true
        }

        Label {
            id: label2
            text: qsTr("Secret Key")
        }

        TextField {
            id: secretKeyText
            text: config.secretKey
            Layout.fillWidth: true
        }

        Label {
            id: label3
            text: qsTr("Sound Format")
        }

        TextField {
            id: soundExtText
            text: config.ext
            Layout.fillWidth: true
        }

        Label {
            id: label4
            text: qsTr("Voice")
        }

        TextField {
            id: voiceText
            text: config.voice
            Layout.fillWidth: true
        }
    }

    Connections {
        target: linkText
        onEditingFinished: config.link = linkText.text
    }

    Connections {
        target: appKeyText
        onEditingFinished: config.appKey = appKeyText.text
    }

    Connections {
        target: secretKeyText
        onEditingFinished: config.secretKey = secretKeyText.text
    }

    Connections {
        target: soundExtText
        onEditingFinished: config.ext = soundExtText.text
    }

    Connections {
        target: voiceText
        onEditingFinished: config.voice = voiceText.text
    }
}
