import QtQuick 2.4

Item {
    width: 600
    height: 30
    property alias signal_strengthText: signal_strength.text
    property alias circleColor: circle.color
    property alias component_nameText: component_name.text
    property alias component_typeText: component_type.text

    Rectangle {
        id: element
        color: "#989898"
        anchors.fill: parent

        Text {
            id: component_type
            x: 116
            y: 17
            width: 124
            height: 16
            color: "#ffffff"
            text: qsTr("Text")
            anchors.verticalCenter: parent.verticalCenter
            anchors.right: minus.left
            font.pixelSize: 15
            horizontalAlignment: Text.AlignHCenter
            wrapMode: Text.WordWrap
            anchors.rightMargin: 5
            font.family: "Arial"
        }

        Text {
            id: component_name
            y: 17
            width: 192
            height: 16
            color: "#ffffff"
            text: qsTr("Text")
            elide: Text.ElideLeft
            anchors.verticalCenter: parent.verticalCenter
            anchors.left: minus.right
            font.pixelSize: 15
            horizontalAlignment: Text.AlignHCenter
            lineHeightMode: Text.FixedHeight
            wrapMode: Text.WordWrap
            fontSizeMode: Text.FixedSize
            anchors.leftMargin: 5
            font.family: "Arial"
        }

        Text {
            id: minus
            x: 245
            y: 17
            width: 19
            height: 16
            color: "#ffffff"
            text: qsTr("-")
            anchors.verticalCenter: parent.verticalCenter
            font.pixelSize: 15
            horizontalAlignment: Text.AlignHCenter
            anchors.verticalCenterOffset: 0
        }

        Rectangle {
            id: circle
            y: 22
            width: 10
            height: 10
            color: "#ff0000"
            radius: width * 0.5
            anchors.verticalCenter: parent.verticalCenter
            anchors.left: parent.left
            anchors.leftMargin: 30
        }

        Text {
            id: signal_strength
            x: 552
            y: 17
            color: "#ffffff"
            text: qsTr("Text")
            anchors.verticalCenter: parent.verticalCenter
            anchors.right: parent.right
            font.pixelSize: 15
            horizontalAlignment: Text.AlignHCenter
            anchors.rightMargin: 35
            font.family: "Arial"
        }
    }
}
