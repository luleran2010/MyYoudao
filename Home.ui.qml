import QtQuick 2.9
import QtQuick.Controls 2.2
import QtQuick.Layouts 1.3

Page {
    id: page
    width: 640
    height: 440

    title: qsTr("Dictionary")

    TabBar {
        id: tabBar
        anchors.top: parent.top
        anchors.topMargin: 0
        anchors.left: parent.left
        anchors.leftMargin: 0
        anchors.right: parent.right

        TabButton {
            id: dictionaryButton
            text: qsTr("Dictionary")
        }

        TabButton {
            id: translationButton
            text: qsTr("Translation")
        }
    }

    StackLayout {
        anchors.top: tabBar.bottom
        anchors.right: parent.right
        anchors.bottom: parent.bottom
        anchors.left: parent.left
        currentIndex: tabBar.currentIndex

        ColumnLayout {
            anchors.fill: parent

            TextField {
                id: wordText
                text: ""
                placeholderText: "Word or Phrase"
                Layout.fillWidth: true
            }

            ScrollView {
                Layout.fillHeight: true
                Layout.fillWidth: true
                TextArea {
                    id: explainText
                    x: -10
                    y: 0
                    placeholderText: "Explaination"
                    text: qsTr("")
                    wrapMode: Text.WordWrap
                    textFormat: Text.RichText
                    Layout.fillHeight: true
                    Layout.fillWidth: true

                    readOnly: true
                    selectByMouse: true
                    selectByKeyboard: true
                }
            }
        }

        ColumnLayout {
            anchors.fill: parent
            Layout.fillHeight: true
            Layout.fillWidth: true

            ScrollView {
                Layout.fillHeight: true
                Layout.fillWidth: true
                TextArea {
                    id: sourceText
                    wrapMode: Text.WordWrap
                    placeholderText: "Source Text"
                    Layout.fillWidth: true
                    Layout.fillHeight: true

                    selectByMouse: true
                    selectByKeyboard: true
                }
            }

            ScrollView {
                id: scrollView
                Layout.fillHeight: true
                Layout.fillWidth: true
                TextArea {
                    id: translationText
                    wrapMode: Text.WordWrap
                    placeholderText: "Translation Text"
                    textFormat: Text.PlainText
                    Layout.fillWidth: true
                    Layout.fillHeight: true

                    readOnly: true
                    selectByMouse: true
                    selectByKeyboard: true
                }
            }
        }
    }

    Connections {
        target: wordText
        onEditingFinished: {
            if (wordText.text != "") {
                request.q = wordText.text
                dict.translate(request)
            }
        }
    }

    Connections {
        target: sourceText
        onEditingFinished: {
            if (sourceText.text != "") {
                request.q = sourceText.text
                dict.translate(request)
            }
        }
    }

    Connections {
        target: dict
        onLookupFinished: {
            if (tabBar.currentIndex == 0)
                explainText.text = dict.result.toHtml()
            else
                translationText.text = dict.result.translation
        }
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

    Connections {
        target: explainText
        onLinkActivated: print(link)
    }
}
