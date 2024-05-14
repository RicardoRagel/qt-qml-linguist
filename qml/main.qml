import QtQuick 2.14
import QtQuick.Window 2.3
import QtQuick.Controls 1.4
import QtQuick.Controls.Styles 1.4
import QtQuick.Dialogs 1.3

// Import C++ data handlers
import DataManager 1.0

// App Window
ApplicationWindow
{
    id: root
    property color appWindowColor:      Qt.rgba(30/255,30/255,30/255, 1)

    // Windows Configuration
    title: "App"
    visible: true
    visibility : Window.Maximized
    x: 0
    y: 0
    minimumWidth: Screen.width * 0.5
    minimumHeight: Screen.height * 0.75
    color: appWindowColor

    // Manage the app starup
    Component.onCompleted:
    {
    }

    /*
        CONTENT
    */
    Rectangle
    {
        id: appBackground
        visible: true
        anchors.fill: parent
        color: "transparent"

        Column
        {
            anchors.centerIn: parent
            spacing: 25

            property int fontSize: 30

            Text
            {
                anchors.horizontalCenter: parent.horizontalCenter

                font.pointSize: parent.fontSize
                color: "white"

                text: DataManager.label
            }

            Text
            {
                anchors.horizontalCenter: parent.horizontalCenter

                font.pointSize: parent.fontSize
                color: "white"

                text: qsTr("farewell")
            }

            Row
            {
                anchors.horizontalCenter: parent.horizontalCenter
                spacing: 20

                Button
                {
                    width: 50; height: 50
                    onClicked: DataManager.setLanguage("English")
                    text: "en"
                }
                Button
                {
                    width: 50; height: 50
                    onClicked: DataManager.setLanguage("Spanish")
                    text: "es"
                }
                Button
                {
                    width: 50; height: 50
                    onClicked: DataManager.setLanguage("German")
                    text: "de"
                }
            }
        }//column
    }//background
}
