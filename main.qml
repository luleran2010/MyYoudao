import QtQuick 2.9
import QtQuick.Controls 2.2
import QtQuick.Layouts 1.3

import org.leran.myyoudao 1.0

ApplicationWindow {
    id: window
    visible: true
    width: 640
    height: 480
    title: qsTr("Stack")

    ListModel {
        id: languageList
        ListElement {
            value: "zh-CHS"
            text: "Simplified Chinese"
        }
        ListElement {
            value: "ja"
            text: "Japanese"
        }
        ListElement {
            value: "EN"
            text: "English"
        }
        ListElement {
            value: "ko"
            text: "Korean"
        }
        ListElement {
            value: "fr"
            text: "French"
        }
        ListElement {
            value: "ru"
            text: "Russian"
        }
        ListElement {
            value: "pt"
            text: "Portuguese"
        }
        ListElement {
            value: "es"
            text: "Spanish"
        }
        ListElement {
            value: "vi"
            text: "Vietnamese"
        }
        ListElement {
            value: "de"
            text: "German"
        }
        ListElement {
            value: "ar"
            text: "Arabic"
        }
        ListElement {
            value: "id"
            text: "Indonesian"
        }
    }

    header: ToolBar {
        contentHeight: toolButton.implicitHeight

        ToolButton {
            id: toolButton
            text: stackView.depth > 1 ? "\u25C0" : "\u2630"
            font.pixelSize: Qt.application.font.pixelSize * 1.6
            onClicked: {
                if (stackView.depth > 1) {
                    stackView.pop()
                } else {
                    drawer.open()
                }
            }
        }

        Label {
            text: stackView.currentItem.title
            anchors.centerIn: parent
        }
    }

    Drawer {
        id: drawer
        width: window.width * 0.66
        height: window.height

        Column {
            id: column
            anchors.fill: parent

            ItemDelegate {
                text: qsTr("Settings")
                width: parent.width
                onClicked: {
                    stackView.push("Settings.ui.qml")
                    drawer.close()
                }
            }
            ItemDelegate {
                text: qsTr("About")
                width: parent.width
                onClicked: {
                    stackView.push("About.ui.qml")
                    drawer.close()
                }
            }

            ComboBox {
                id: sourceLanguageSelection
                textRole: "text"
                currentIndex: 2
                width: parent.width * 0.66
                model: languageList
            }
            ComboBox {
                id: targetLanguageSelection
                textRole: "text"
                currentIndex: 0
                width: parent.width * 0.66
                model: languageList
            }

        }
    }

    StackView {
        id: stackView
        anchors.fill: parent
        initialItem: "Home.ui.qml"
    }

    Connections {
        target: sourceLanguageSelection
        onActivated: request.from = languageList.get(
                         sourceLanguageSelection.currentIndex).value
    }

    Connections {
        target: targetLanguageSelection
        onActivated: request.to = languageList.get(
                         targetLanguageSelection.currentIndex).value
    }
}
