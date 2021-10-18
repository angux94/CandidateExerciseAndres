#include "classgyro.h"

#include <QDebug>
#include <QTime>
#include <QTimer>
#include <QCoreApplication>
#include <math.h>

ClassGYRO::ClassGYRO(QObject *parent) : QObject(parent), m_time(0),
     m_mgSstrength("0%"),m_mgStatusColor("green"),m_valueMgStrength(25),m_valueMgColor(0),m_mgFlag(false),
     m_bgSstrength("0%"),m_bgStatusColor("green"),m_valueBgStrength(100),m_valueBgColor(0),m_bgFlag(false)
{
    QTimer *timer = new QTimer(this);
    connect(timer, SIGNAL(timeout()),this,SLOT(globalTimer()));

    // Connectors to Main GYRO
    connect(timer, SIGNAL(timeout()),this,SLOT(mgStrengthGen()));
    connect(timer, SIGNAL(timeout()),this,SLOT(mgStatusGen()));

    // Connectors to Backup GYRO
    connect(timer, SIGNAL(timeout()),this,SLOT(bgStrengthGen()));
    connect(timer, SIGNAL(timeout()),this,SLOT(bgStatusGen()));

    timer->start(50);
}

void ClassGYRO::globalTimer(){
    // Stablish a global timer to handle the application
    m_time++;
    //qDebug() << "time: " << m_time;
}

void ClassGYRO::delay()
{
    //Delay function in case there's the need to use
    QTime dieTime= QTime::currentTime().addMSecs(50);
    while (QTime::currentTime() < dieTime)
        QCoreApplication::processEvents(QEventLoop::AllEvents, 100);
}

// Return values to QML
QString ClassGYRO::mgSstrength()
{
    return m_mgSstrength;
}

QString ClassGYRO::mgStatusColor()
{
    return m_mgStatusColor;
}

QString ClassGYRO::bgSstrength()
{
    return m_bgSstrength;
}

QString ClassGYRO::bgStatusColor()
{
    return m_bgStatusColor;
}

// Main GYRO behavior
void ClassGYRO::setMgSstrength(QString newSstrength)
{
    // Update the value and notify it
    if(m_mgSstrength != newSstrength){
        m_mgSstrength = newSstrength;
        emit mgSstrengthChanged();
    }
}

void ClassGYRO::setMgStatusColor(QString newStatusColor)
{
    // Update the value and notify it
    if(m_mgStatusColor != newStatusColor){
        m_mgStatusColor = newStatusColor;
        emit mgStatusColorChanged();
    }
}

void ClassGYRO::mgStrengthGen()
{
    // Generates the signal strength changes

    double value = 1;
    QString string;

    if(m_valueMgStrength >= 75){
        m_mgFlag = true;
    }
    if (m_valueMgStrength <= 25){
        m_mgFlag = false;
    }

    //Set a timing for increments
    double div;
    div = m_time % 4;
    if(div == 0){
        if(!m_mgFlag) m_valueMgStrength += value;
        if(m_mgFlag) m_valueMgStrength -= value;
    }

    //qDebug() << "value" << m_valueMgStrength;
    string = QString::number(m_valueMgStrength) + "%";
    setMgSstrength(string);
}

void ClassGYRO::mgStatusGen()
{
    // Generates the status changes

    //set a timing for change of status based on global timer
    double div;
    div = m_time % 25;
    if (div == 0){
        m_valueMgColor = rand() % 60 + 1;
        QString string;

        if(m_valueMgColor < 20 && m_valueMgColor >= 0){
            string = "green";
        } else if (m_valueMgColor < 40 && m_valueMgColor >= 20){
            string = "orange";
        } else if (m_valueMgColor <= 60 && m_valueMgColor >= 40){
            string = "red";
        }
        //qDebug() << "color: " << string;
        setMgStatusColor(string);
    }
}


// Backup GYRO behavior
void ClassGYRO::setBgSstrength(QString newSstrength)
{
    // Update the value and notify it
    if(m_bgSstrength != newSstrength){
        m_bgSstrength = newSstrength;
        emit bgSstrengthChanged();
    }
}

void ClassGYRO::setBgStatusColor(QString newStatusColor)
{
    // Update the value and notify it
    if(m_bgStatusColor != newStatusColor){
        m_bgStatusColor = newStatusColor;
        emit bgStatusColorChanged();
    }
}

void ClassGYRO::bgStrengthGen()
{
    // Generates the signal strength changes

    double value = 1;
    QString string;

    if(m_valueBgStrength >= 100){
        m_bgFlag = true;
    }
    if (m_valueBgStrength <= 0){
        m_bgFlag = false;
    }

    //Set a timing for increments
    double div;
    div = m_time % 3;
    if(div == 0){
        if(!m_bgFlag) m_valueBgStrength += value;
        if(m_bgFlag) m_valueBgStrength -= value;
    }


    //qDebug() << "value" << m_valueBgStrength;
    string = QString::number(m_valueBgStrength) + "%";
    setBgSstrength(string);
}

void ClassGYRO::bgStatusGen()
{
    // Generates the status changes

    //set a timing for change of status based on global timer
    double div;
    div = m_time % 40;
    if (div == 0){
        m_valueBgColor = rand() % 60 + 1;
        QString string;

        if(m_valueBgColor < 20 && m_valueBgColor >= 0){
            string = "green";
        } else if (m_valueBgColor < 40 && m_valueBgColor >= 20){
            string = "orange";
        } else if (m_valueBgColor <= 60 && m_valueBgColor >= 40){
            string = "red";
        }
        //qDebug() << "color: " << string;
        setBgStatusColor(string);
    }
}

