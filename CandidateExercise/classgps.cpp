#include "classgps.h"

#include <QDebug>
#include <QTime>
#include <QTimer>
#include <QCoreApplication>
#include <math.h>

ClassGPS::ClassGPS(QObject *parent) : QObject(parent), m_time(0),
    m_frontSstrength("0%"),m_frontStatusColor("green"),m_valueFrontStrength(1),m_valueFrontColor(0),m_frontFlag(false),
    m_rearSstrength("0%"),m_rearStatusColor("green"),m_valueRearStrength(100),m_valueRearColor(0),m_rearFlag(false),
    m_sbSstrength("0%"),m_sbStatusColor("green"),m_valueSbStrength(25),m_valueSbColor(0),m_sbFlag(false),
    m_portSstrength("0%"),m_portStatusColor("green"),m_valuePortStrength(75),m_valuePortColor(0),m_portFlag(false)
{
    QTimer *timer = new QTimer(this);
    connect(timer, SIGNAL(timeout()),this,SLOT(globalTimer()));

    // Connectors to Front GPS
    connect(timer, SIGNAL(timeout()),this,SLOT(frontStrengthGen()));
    connect(timer, SIGNAL(timeout()),this,SLOT(frontStatusGen()));

    // Connectors to Rear GPS
    connect(timer, SIGNAL(timeout()),this,SLOT(rearStrengthGen()));
    connect(timer, SIGNAL(timeout()),this,SLOT(rearStatusGen()));

    // Connectors to Starboard GPS
    connect(timer, SIGNAL(timeout()),this,SLOT(sbStrengthGen()));
    connect(timer, SIGNAL(timeout()),this,SLOT(sbStatusGen()));

    // Connectors to port GPS
    connect(timer, SIGNAL(timeout()),this,SLOT(portStrengthGen()));
    connect(timer, SIGNAL(timeout()),this,SLOT(portStatusGen()));

    timer->start(50);
}

void ClassGPS::globalTimer(){
    // Stablish a global timer to handle the application
    m_time++;
    //qDebug() << "time: " << m_time;
}
void ClassGPS::delay()
{
    //Delay function in case there's the need to use
    QTime dieTime= QTime::currentTime().addMSecs(50);
    while (QTime::currentTime() < dieTime)
        QCoreApplication::processEvents(QEventLoop::AllEvents, 100);
}

// Return values to QML
QString ClassGPS::frontSstrength()
{
    return m_frontSstrength;
}

QString ClassGPS::frontStatusColor()
{
    return m_frontStatusColor;
}

QString ClassGPS::rearSstrength()
{
    return m_rearSstrength;
}

QString ClassGPS::rearStatusColor()
{
    return m_rearStatusColor;
}

QString ClassGPS::sbSstrength()
{
    return m_sbSstrength;
}

QString ClassGPS::sbStatusColor()
{
    return m_sbStatusColor;
}

QString ClassGPS::portSstrength()
{
    return m_portSstrength;
}

QString ClassGPS::portStatusColor()
{
    return m_portStatusColor;
}


// Front GPS behavior
void ClassGPS::setfrontSstrength(QString newSstrength)
{
    // Update the value and notify it
    if(m_frontSstrength != newSstrength){
        m_frontSstrength = newSstrength;
        emit frontSstrengthChanged();
    }
}

void ClassGPS::setfrontStatusColor(QString newStatusColor)
{
    // Update the value and notify it
    if(m_frontStatusColor != newStatusColor){
        m_frontStatusColor = newStatusColor;
        emit frontstatusColorChanged();
    }
}

void ClassGPS::frontStrengthGen()
{
    // Generates the signal strength changes

    double value = 1;
    QString string;

    if(m_valueFrontStrength >= 100){
        m_frontFlag = true;
    }
    if (m_valueFrontStrength <= 0){
        m_frontFlag = false;
    }

    //Set a timing for increments
    double div;
    div = m_time % 2;
    if(div == 0){
        if(!m_frontFlag) m_valueFrontStrength += value;
        if(m_frontFlag) m_valueFrontStrength -= value;
    }


    //qDebug() << "value" << m_valueFrontStrength;
    string = QString::number(m_valueFrontStrength) + "%";
    setfrontSstrength(string);
}

void ClassGPS::frontStatusGen()
{
    // Generates the status changes

    //set a timing for change of status based on global timer
    double div;
    div = m_time % 50;
    if (div == 0){
        m_valueFrontColor = rand() % 60 + 1;
        QString string;

        if(m_valueFrontColor < 20 && m_valueFrontColor >= 0){
            string = "green";
        } else if (m_valueFrontColor < 40 && m_valueFrontColor >= 20){
            string = "orange";
        } else if (m_valueFrontColor <= 60 && m_valueFrontColor >= 40){
            string = "red";
        }
        //qDebug() << "color: " << string;
        setfrontStatusColor(string);
    }
}


// Rear GPS behavior
void ClassGPS::setRearSstrength(QString newSstrength)
{
    // Update the value and notify it
    if(m_rearSstrength != newSstrength){
        m_rearSstrength = newSstrength;
        emit rearSstrengthChanged();
    }
}

void ClassGPS::setRearStatusColor(QString newStatusColor)
{
    // Update the value and notify it
    if(m_rearStatusColor != newStatusColor){
        m_rearStatusColor = newStatusColor;
        emit rearStatusColorChanged();
    }
}

void ClassGPS::rearStrengthGen()
{
    // Generates the signal strength changes

    double value = 1;
    QString string;

    if(m_valueRearStrength >= 100){
        m_rearFlag = true;
    }
    if (m_valueRearStrength <= 0){
        m_rearFlag = false;
    }

    //Set a timing for increments
    double div;
    div = m_time % 3;
    if(div == 0){
        if(!m_rearFlag) m_valueRearStrength += value;
        if(m_rearFlag) m_valueRearStrength -= value;
    }


    //qDebug() << "value" << m_valueRearStrength;
    string = QString::number(m_valueRearStrength) + "%";
    setRearSstrength(string);
}

void ClassGPS::rearStatusGen()
{
    // Generates the status changes

    //set a timing for change of status based on global timer
    double div;
    div = m_time % 40;
    if (div == 0){
        m_valueRearColor = rand() % 60 + 1;
        QString string;

        if(m_valueRearColor < 20 && m_valueRearColor >= 0){
            string = "green";
        } else if (m_valueRearColor < 40 && m_valueRearColor >= 20){
            string = "orange";
        } else if (m_valueRearColor <= 60 && m_valueRearColor >= 40){
            string = "red";
        }
        //qDebug() << "color: " << string;
        setRearStatusColor(string);
    }
}


// Starboard GPS behavior
void ClassGPS::setSbSstrength(QString newSstrength)
{
    // Update the value and notify it
    if(m_sbSstrength != newSstrength){
        m_sbSstrength = newSstrength;
        emit sbSstrengthChanged();
    }
}

void ClassGPS::setSbStatusColor(QString newStatusColor)
{
    // Update the value and notify it
    if(m_sbStatusColor != newStatusColor){
        m_sbStatusColor = newStatusColor;
        emit sbStatusColorChanged();
    }
}

void ClassGPS::sbStrengthGen()
{
    // Generates the signal strength changes

    double value = 1;
    QString string;

    if(m_valueSbStrength >= 75){
        m_sbFlag = true;
    }
    if (m_valueSbStrength <= 25){
        m_sbFlag = false;
    }

    //Set a timing for increments
    double div;
    div = m_time % 4;
    if(div == 0){
        if(!m_sbFlag) m_valueSbStrength += value;
        if(m_sbFlag) m_valueSbStrength -= value;
    }

    //qDebug() << "value" << m_valueSbStrength;
    string = QString::number(m_valueSbStrength) + "%";
    setSbSstrength(string);
}

void ClassGPS::sbStatusGen()
{
    // Generates the status changes

    //set a timing for change of status based on global timer
    double div;
    div = m_time % 65;
    if (div == 0){
        m_valueSbColor = rand() % 60 + 1;
        QString string;

        if(m_valueSbColor < 20 && m_valueSbColor >= 0){
            string = "green";
        } else if (m_valueSbColor < 40 && m_valueSbColor >= 20){
            string = "orange";
        } else if (m_valueSbColor <= 60 && m_valueSbColor >= 40){
            string = "red";
        }
        //qDebug() << "color: " << string;
        setSbStatusColor(string);
    }
}


// Port GPS behavior
void ClassGPS::setPortSstrength(QString newSstrength)
{
    // Update the value and notify it
    if(m_portSstrength != newSstrength){
        m_portSstrength = newSstrength;
        emit portSstrengthChanged();
    }
}

void ClassGPS::setPortStatusColor(QString newStatusColor)
{
    // Update the value and notify it
    if(m_portStatusColor != newStatusColor){
        m_portStatusColor = newStatusColor;
        emit portStatusColorChanged();
    }
}

void ClassGPS::portStrengthGen()
{
    // Generates the signal strength changes

    double value = 1;
    QString string;

    if(m_valuePortStrength >= 75){
        m_portFlag = true;
    }
    if (m_valuePortStrength <= 25){
        m_portFlag = false;
    }

    //Set a timing for increments
    double div;
    div = m_time % 4;
    if(div == 0){
        if(!m_portFlag) m_valuePortStrength += value;
        if(m_portFlag) m_valuePortStrength -= value;
    }

    //qDebug() << "value" << m_valuePortStrength;
    string = QString::number(m_valuePortStrength) + "%";
    setPortSstrength(string);
}

void ClassGPS::portStatusGen()
{
    // Generates the status changes

    //set a timing for change of status based on global timer
    double div;
    div = m_time % 25;
    if (div == 0){
        m_valuePortColor = rand() % 60 + 1;
        QString string;

        if(m_valuePortColor < 20 && m_valuePortColor >= 0){
            string = "green";
        } else if (m_valuePortColor < 40 && m_valuePortColor >= 20){
            string = "orange";
        } else if (m_valuePortColor <= 60 && m_valuePortColor >= 40){
            string = "red";
        }
        //qDebug() << "color: " << string;
        setPortStatusColor(string);
    }
}
