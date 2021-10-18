#include "classcompass.h"

#include <QDebug>
#include <QTime>
#include <QTimer>
#include <QCoreApplication>
#include <math.h>

ClassCOMPASS::ClassCOMPASS(QObject *parent) : QObject(parent), m_time(0),
    m_c1Sstrength("0%"),m_c1StatusColor("green"),m_valueC1Strength(0),m_valueC1Color(0),m_c1Flag(false),
    m_c2Sstrength("0%"),m_c2StatusColor("green"),m_valueC2Strength(100),m_valueC2Color(0),m_c2Flag(false),
    m_c3Sstrength("0%"),m_c3StatusColor("green"),m_valueC3Strength(25),m_valueC3Color(0),m_c3Flag(false),
    m_c4Sstrength("0%"),m_c4StatusColor("green"),m_valueC4Strength(75),m_valueC4Color(0),m_c4Flag(false)
{
    QTimer *timer = new QTimer(this);
    connect(timer, SIGNAL(timeout()),this,SLOT(globalTimer()));

    // Connectors to Compass 1
    connect(timer, SIGNAL(timeout()),this,SLOT(c1StrengthGen()));
    connect(timer, SIGNAL(timeout()),this,SLOT(c1StatusGen()));

    // Connectors to Compass 2
    connect(timer, SIGNAL(timeout()),this,SLOT(c2StrengthGen()));
    connect(timer, SIGNAL(timeout()),this,SLOT(c2StatusGen()));

    // Connectors to Compass 3
    connect(timer, SIGNAL(timeout()),this,SLOT(c3StrengthGen()));
    connect(timer, SIGNAL(timeout()),this,SLOT(c3StatusGen()));

    // Connectors to Compass 4
    connect(timer, SIGNAL(timeout()),this,SLOT(c4StrengthGen()));
    connect(timer, SIGNAL(timeout()),this,SLOT(c4StatusGen()));

    timer->start(50);
}

void ClassCOMPASS::globalTimer(){
    // Stablish a global timer to handle the application
    m_time++;
    //qDebug() << "time: " << m_time;
}

void ClassCOMPASS::delay()
{
    //Delay function in case there's the need to use
    QTime dieTime= QTime::currentTime().addMSecs(50);
    while (QTime::currentTime() < dieTime)
        QCoreApplication::processEvents(QEventLoop::AllEvents, 100);
}

// Return values to QML
QString ClassCOMPASS::c1Sstrength()
{
    return m_c1Sstrength;
}

QString ClassCOMPASS::c1StatusColor()
{
    return m_c1StatusColor;
}

QString ClassCOMPASS::c2Sstrength()
{
    return m_c2Sstrength;
}

QString ClassCOMPASS::c2StatusColor()
{
    return m_c2StatusColor;
}

QString ClassCOMPASS::c3Sstrength()
{
    return m_c3Sstrength;
}

QString ClassCOMPASS::c3StatusColor()
{
    return m_c3StatusColor;
}

QString ClassCOMPASS::c4Sstrength()
{
    return m_c4Sstrength;
}

QString ClassCOMPASS::c4StatusColor()
{
    return m_c4StatusColor;
}


// Compass 1 behavior
void ClassCOMPASS::setC1Sstrength(QString newSstrength)
{
    // Update the value and notify it
    if(m_c1Sstrength != newSstrength){
        m_c1Sstrength = newSstrength;
        emit c1SstrengthChanged();
    }
}

void ClassCOMPASS::setC1StatusColor(QString newStatusColor)
{
    // Update the value and notify it
    if(m_c1StatusColor != newStatusColor){
        m_c1StatusColor = newStatusColor;
        emit c1StatusColorChanged();
    }
}

void ClassCOMPASS::c1StrengthGen()
{
    // Generates the signal strength changes

    double value = 1;
    QString string;

    if(m_valueC1Strength >= 100){
        m_c1Flag = true;
    }
    if (m_valueC1Strength <= 0){
        m_c1Flag = false;
    }

    //Set a timing for increments
    double div;
    div = m_time % 2;
    if(div == 0){
        if(!m_c1Flag) m_valueC1Strength += value;
        if(m_c1Flag) m_valueC1Strength -= value;
    }


    //qDebug() << "value" << m_valueC1Strength;
    string = QString::number(m_valueC1Strength) + "%";
    setC1Sstrength(string);
}

void ClassCOMPASS::c1StatusGen()
{
    // Generates the status changes

    //set a timing for change of status based on global timer
    double div;
    div = m_time % 50;
    if (div == 0){
        m_valueC1Color = rand() % 60 + 1;
        QString string;

        if(m_valueC1Color < 20 && m_valueC1Color >= 0){
            string = "green";
        } else if (m_valueC1Color < 40 && m_valueC1Color >= 20){
            string = "orange";
        } else if (m_valueC1Color <= 60 && m_valueC1Color >= 40){
            string = "red";
        }
        //qDebug() << "color: " << string;
        setC1StatusColor(string);
    }
}


// Compass 2 behavior
void ClassCOMPASS::setC2Sstrength(QString newSstrength)
{
    // Update the value and notify it
    if(m_c2Sstrength != newSstrength){
        m_c2Sstrength = newSstrength;
        emit c2SstrengthChanged();
    }
}

void ClassCOMPASS::setC2StatusColor(QString newStatusColor)
{
    // Update the value and notify it
    if(m_c2StatusColor != newStatusColor){
        m_c2StatusColor = newStatusColor;
        emit c2StatusColorChanged();
    }
}

void ClassCOMPASS::c2StrengthGen()
{
    // Generates the signal strength changes

    double value = 1;
    QString string;

    if(m_valueC2Strength >= 100){
        m_c2Flag = true;
    }
    if (m_valueC2Strength <= 0){
        m_c2Flag = false;
    }

    //Set a timing for increments
    double div;
    div = m_time % 3;
    if(div == 0){
        if(!m_c2Flag) m_valueC2Strength += value;
        if(m_c2Flag) m_valueC2Strength -= value;
    }


    //qDebug() << "value" << m_valueC2Strength;
    string = QString::number(m_valueC2Strength) + "%";
    setC2Sstrength(string);
}

void ClassCOMPASS::c2StatusGen()
{
    // Generates the status changes

    //set a timing for change of status based on global timer
    double div;
    div = m_time % 40;
    if (div == 0){
        m_valueC2Color = rand() % 60 + 1;
        QString string;

        if(m_valueC2Color < 20 && m_valueC2Color >= 0){
            string = "green";
        } else if (m_valueC2Color < 40 && m_valueC2Color >= 20){
            string = "orange";
        } else if (m_valueC2Color <= 60 && m_valueC2Color >= 40){
            string = "red";
        }
        //qDebug() << "color: " << string;
        setC2StatusColor(string);
    }
}


// Compass 3 behavior
void ClassCOMPASS::setC3Sstrength(QString newSstrength)
{
    // Update the value and notify it
    if(m_c3Sstrength != newSstrength){
        m_c3Sstrength = newSstrength;
        emit c3SstrengthChanged();
    }
}

void ClassCOMPASS::setC3StatusColor(QString newStatusColor)
{
    // Update the value and notify it
    if(m_c3StatusColor != newStatusColor){
        m_c3StatusColor = newStatusColor;
        emit c3StatusColorChanged();
    }
}

void ClassCOMPASS::c3StrengthGen()
{
    // Generates the signal strength changes

    double value = 1;
    QString string;

    if(m_valueC3Strength >= 75){
        m_c3Flag = true;
    }
    if (m_valueC3Strength <= 25){
        m_c3Flag = false;
    }

    //Set a timing for increments
    double div;
    div = m_time % 4;
    if(div == 0){
        if(!m_c3Flag) m_valueC3Strength += value;
        if(m_c3Flag) m_valueC3Strength -= value;
    }

    //qDebug() << "value" << m_valueC3Strength;
    string = QString::number(m_valueC3Strength) + "%";
    setC3Sstrength(string);
}

void ClassCOMPASS::c3StatusGen()
{
    // Generates the status changes

    //set a timing for change of status based on global timer
    double div;
    div = m_time % 65;
    if (div == 0){
        m_valueC3Color = rand() % 60 + 1;
        QString string;

        if(m_valueC3Color < 20 && m_valueC3Color >= 0){
            string = "green";
        } else if (m_valueC3Color < 40 && m_valueC3Color >= 20){
            string = "orange";
        } else if (m_valueC3Color <= 60 && m_valueC3Color >= 40){
            string = "red";
        }
        //qDebug() << "color: " << string;
        setC3StatusColor(string);
    }
}


// Compass 4 behavior
void ClassCOMPASS::setC4Sstrength(QString newSstrength)
{
    // Update the value and notify it
    if(m_c4Sstrength != newSstrength){
        m_c4Sstrength = newSstrength;
        emit c4SstrengthChanged();
    }
}

void ClassCOMPASS::setC4StatusColor(QString newStatusColor)
{
    // Update the value and notify it
    if(m_c4StatusColor != newStatusColor){
        m_c4StatusColor = newStatusColor;
        emit c4StatusColorChanged();
    }
}

void ClassCOMPASS::c4StrengthGen()
{
    // Generates the signal strength changes

    double value = 1;
    QString string;

    if(m_valueC4Strength >= 75){
        m_c4Flag = true;
    }
    if (m_valueC4Strength <= 25){
        m_c4Flag = false;
    }

    //Set a timing for increments
    double div;
    div = m_time % 4;
    if(div == 0){
        if(!m_c4Flag) m_valueC4Strength += value;
        if(m_c4Flag) m_valueC4Strength -= value;
    }

    //qDebug() << "value" << m_valueC4Strength;
    string = QString::number(m_valueC4Strength) + "%";
    setC4Sstrength(string);
}

void ClassCOMPASS::c4StatusGen()
{
    // Generates the status changes

    //set a timing for change of status based on global timer
    double div;
    div = m_time % 25;
    if (div == 0){
        m_valueC4Color = rand() % 60 + 1;
        QString string;

        if(m_valueC4Color < 20 && m_valueC4Color >= 0){
            string = "green";
        } else if (m_valueC4Color < 40 && m_valueC4Color >= 20){
            string = "orange";
        } else if (m_valueC4Color <= 60 && m_valueC4Color >= 40){
            string = "red";
        }
        //qDebug() << "color: " << string;
        setC4StatusColor(string);
    }
}
