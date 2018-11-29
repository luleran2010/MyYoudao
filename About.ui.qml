import QtQuick 2.9
import QtQuick.Controls 2.2

Page {
    width: 640
    height: 440
    title: "About"

    TextArea {
        id: textArea
        text: "<h1>MyYouao</h1><br/><p>This is a simple program developed by Leran LU.</p>"
        horizontalAlignment: Text.AlignHCenter
        verticalAlignment: Text.AlignVCenter
        textFormat: Text.RichText
        anchors.fill: parent
    }

}
