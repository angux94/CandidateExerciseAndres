import QtQuick 2.15
import QtQuick.Window 2.15
import QtQuick.Controls
import ce.classgps 1.0
import ce.classcompass 1.0
import ce.classanemometer 1.0
import ce.classgyro 1.0

Window {
    width: 640
    height: 480
    visible: true
    title: qsTr("Candidate Exercise Andres Gutierrez")

    Background {
        id: background
        anchors.fill: parent

        ClassGPS{
            id: classFrontGPS
        }

        Element{
            id: frontGPS
            component_nameText: "Front GPS"
            component_typeText: "[GPS]"
            anchors.left: parent.left
            anchors.right: parent.right
            anchors.top: parent.top
            anchors.topMargin: 30
            anchors.rightMargin: 20
            anchors.leftMargin: 20
            signal_strengthText: classFrontGPS.frontSstrength
            circleColor: classFrontGPS.frontStatusColor
        }

        ClassGPS{
            id: classRearGPS
        }

        Element{
            id: rearGPS
            component_nameText: "Rear GPS"
            component_typeText: "[GPS]"
            anchors.left: parent.left
            anchors.right: parent.right
            anchors.top: frontGPS.bottom
            anchors.topMargin: 5
            anchors.rightMargin: 20
            anchors.leftMargin: 20
            signal_strengthText: classRearGPS.rearSstrength
            circleColor: classRearGPS.rearStatusColor
        }

        ClassGPS{
            id: classSbGPS
        }

        Element{
            id: sbGPS
            component_nameText: "Starboard GPS"
            component_typeText: "[GPS]"
            anchors.left: parent.left
            anchors.right: parent.right
            anchors.top: rearGPS.bottom
            anchors.topMargin: 5
            anchors.rightMargin: 20
            anchors.leftMargin: 20
            signal_strengthText: classSbGPS.sbSstrength
            circleColor: classSbGPS.sbStatusColor
        }

        ClassGPS{
            id: classPortGPS
        }

        Element{
            id: portGPS
            component_nameText: "Port GPS"
            component_typeText: "[GPS]"
            anchors.left: parent.left
            anchors.right: parent.right
            anchors.top: sbGPS.bottom
            anchors.topMargin: 5
            anchors.rightMargin: 20
            anchors.leftMargin: 20
            signal_strengthText: classPortGPS.portSstrength
            circleColor: classPortGPS.portStatusColor
        }

        ClassCOMPASS{
            id: classCOMPASS1
        }

        Element{
            id: compass1
            component_nameText: "Compass #1"
            component_typeText: "[COMPASS]"
            anchors.left: parent.left
            anchors.right: parent.right
            anchors.top: portGPS.bottom
            anchors.topMargin: 5
            anchors.rightMargin: 20
            anchors.leftMargin: 20
            signal_strengthText: classCOMPASS1.c1Sstrength
            circleColor: classCOMPASS1.c1StatusColor
        }

        ClassCOMPASS{
            id: classCOMPASS2
        }

        Element{
            id: compass2
            component_nameText: "Compass #2"
            component_typeText: "[COMPASS]"
            anchors.left: parent.left
            anchors.right: parent.right
            anchors.top: compass1.bottom
            anchors.topMargin: 5
            anchors.rightMargin: 20
            anchors.leftMargin: 20
            signal_strengthText: classCOMPASS2.c2Sstrength
            circleColor: classCOMPASS2.c2StatusColor
        }

        ClassCOMPASS{
            id: classCOMPASS3
        }

        Element{
            id: compass3
            component_nameText: "Compass #3"
            component_typeText: "[COMPASS]"
            anchors.left: parent.left
            anchors.right: parent.right
            anchors.top: compass2.bottom
            anchors.topMargin: 5
            anchors.rightMargin: 20
            anchors.leftMargin: 20
            signal_strengthText: classCOMPASS3.c3Sstrength
            circleColor: classCOMPASS3.c3StatusColor
        }

        ClassCOMPASS{
            id: classCOMPASS4
        }

        Element{
            id: compass4
            component_nameText: "Compass #4"
            component_typeText: "[COMPASS]"
            anchors.left: parent.left
            anchors.right: parent.right
            anchors.top: compass3.bottom
            anchors.topMargin: 5
            anchors.rightMargin: 20
            anchors.leftMargin: 20
            signal_strengthText: classCOMPASS4.c4Sstrength
            circleColor: classCOMPASS4.c4StatusColor
        }

        ClassANEMOMETER{
            id: classPA
        }

        Element{
            id: primaryA
            component_nameText: "Primary Anemometer"
            component_typeText: "[ANEMOMETER]"
            anchors.left: parent.left
            anchors.right: parent.right
            anchors.top: compass4.bottom
            anchors.topMargin: 5
            anchors.rightMargin: 20
            anchors.leftMargin: 20
            signal_strengthText: classPA.paSstrength
            circleColor: classPA.paStatusColor
        }

        ClassANEMOMETER{
            id: classSA
        }

        Element{
            id: secondaryA
            component_nameText: "Secondary Anemometer"
            component_typeText: "[ANEMOMETER]"
            anchors.left: parent.left
            anchors.right: parent.right
            anchors.top: primaryA.bottom
            anchors.topMargin: 5
            anchors.rightMargin: 20
            anchors.leftMargin: 20
            signal_strengthText: classSA.saSstrength
            circleColor: classSA.saStatusColor
        }

        ClassGYRO{
            id: classMG
        }

        Element{
            id: mainGYRO
            component_nameText: "Main Gyro"
            component_typeText: "[GYRO]"
            anchors.left: parent.left
            anchors.right: parent.right
            anchors.top: secondaryA.bottom
            anchors.topMargin: 5
            anchors.rightMargin: 20
            anchors.leftMargin: 20
            signal_strengthText: classMG.mgSstrength
            circleColor: classMG.mgStatusColor
        }

        ClassGYRO{
            id: classBG
        }

        Element{
            id: backupGYRO
            component_nameText: "Backup Gyro"
            component_typeText: "[GYRO]"
            anchors.left: parent.left
            anchors.right: parent.right
            anchors.top: mainGYRO.bottom
            anchors.topMargin: 5
            anchors.rightMargin: 20
            anchors.leftMargin: 20
            signal_strengthText: classBG.bgSstrength
            circleColor: classBG.bgStatusColor
        }
    }

}
