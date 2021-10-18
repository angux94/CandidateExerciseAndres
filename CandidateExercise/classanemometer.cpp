#include "classanemometer.h"

#include <QDebug>
#include <QTime>
#include <QTimer>
#include <QCoreApplication>
#include <math.h>

ClassANEMOMETER::ClassANEMOMETER(QObject *parent) : QObject(parent), m_time(0),
    m_paSstrength("0%"),m_paStatusColor("green"),m_valuePaStrength(0),m_valuePaColor(0),m_paFlag(false),
    m_saSstrength("0%"),m_saStatusColor("green"),m_valueSaStrength(100),m_valueSaColor(0),m_saFlag(false)
{
    QTimer *timer = new QTimer(this);
    connect(timer, SIGNAL(timeout()),this,SLOT(globalTimer()));

    // Connectors to Primary Anemometer
    connect(timer, SIGNAL(timeout()),this,SLOT(paStrengthGen()));
    connect(timer, SIGNAL(timeout()),this,SLOT(paStatusGen()));

    // Connectors to Secondary Anemometer
    connect(timer, SIGNAL(timeout()),this,SLOT(saStrengthGen()));
    connect(timer, SIGNAL(timeout()),this,SLOT(saStatusGen()));

    timer->start(50);
}

void ClassANEMOMETER::globalTimer(){
    // Stablish a global timer to handle the application
    m_time++;
    //qDebug() << "time: " << m_time;
}

void ClassANEMOMETER::delay()
{
    //Delay function in case there's the need to use
    QTime dieTime= QTime::currentTime().addMSecs(50);
    while (QTime::currentTime() < dieTime)
        QCoreApplication::processEvents(QEventLoop::AllEvents, 100);
}

// Return values to QML
QString ClassANEMOMETER::paSstrength()
{
    return m_paSstrength;
}

QString ClassANEMOMETER::paStatusColor()
{
    return m_paStatusColor;
}

QString ClassANEMOMETER::saSstrength()
{
    return m_saSstrength;
}

QString ClassANEMOMETER::saStatusColor()
{
    return m_saStatusColor;
}


// Primary Anemometer behavior
void ClassANEMOMETER::setPaSstrength(QString newSstrength)
{
    // Update the value and notify it
    if(m_paSstrength != newSstrength){
        m_paSstrength = newSstrength;
        emit paSstrengthChanged();
    }
}

void ClassANEMOMETER::setPaStatusColor(QString newStatusColor)
{
    // Update the value and notify it
    if(m_paStatusColor != newStatusColor){
        m_paStatusColor = newStatusColor;
        emit paStatusColorChanged();
    }
}

void ClassANEMOMETER::paStrengthGen()
{
    // Generates the signal strength changes

    double value = 1;
    QString string;

    if(m_valuePaStrength >= 100){
        m_paFlag = true;
    }
    if (m_valuePaStrength <= 0){
        m_paFlag = false;
    }

    //Set a timing for increments
    double div;
    div = m_time % 2;
    if(div == 0){
        if(!m_paFlag) m_valuePaStrength += value;
        if(m_paFlag) m_valuePaStrength -= value;
    }


    //qDebug() << "value" << m_valuePaStrength;
    string = QString::number(m_valuePaStrength) + "%";
    setPaSstrength(string);
}

void ClassANEMOMETER::paStatusGen()
{
    // Generates the status changes

    //set a timing for change of status based on global timer
    double div;
    div = m_time % 50;
    if (div == 0){
        m_valuePaColor = rand() % 60 + 1;
        QString string;

        if(m_valuePaColor < 20 && m_valuePaColor >= 0){
            string = "green";
        } else if (m_valuePaColor < 40 && m_valuePaColor >= 20){
            string = "orange";
        } else if (m_valuePaColor <= 60 && m_valuePaColor >= 40){
            string = "red";
        }
        //qDebug() << "color: " << string;
        setPaStatusColor(string);
    }
}


// Secondary Anemometer behavior
void ClassANEMOMETER::setSaSstrength(QString newSstrength)
{
    // Update the value and notify it
    if(m_saSstrength != newSstrength){
        m_saSstrength = newSstrength;
        emit saSstrengthChanged();
    }
}

void ClassANEMOMETER::setSaStatusColor(QString newStatusColor)
{
    // Update the value and notify it
    if(m_saStatusColor != newStatusColor){
        m_saStatusColor = newStatusColor;
        emit saStatusColorChanged();
    }
}

void ClassANEMOMETER::saStrengthGen()
{
    // Generates the signal strength changes

    double value = 1;
    QString string;

    if(m_valueSaStrength >= 75){
        m_saFlag = true;
    }
    if (m_valueSaStrength <= 25){
        m_saFlag = false;
    }

    //Set a timing for increments
    double div;
    div = m_time % 4;
    if(div == 0){
        if(!m_saFlag) m_valueSaStrength += value;
        if(m_saFlag) m_valueSaStrength -= value;
    }

    //qDebug() << "value" << m_valueSaStrength;
    string = QString::number(m_valueSaStrength) + "%";
    setSaSstrength(string);
}

void ClassANEMOMETER::saStatusGen()
{
    // Generates the status changes

    //set a timing for change of status based on global timer
    double div;
    div = m_time % 65;
    if (div == 0){
        m_valueSaColor = rand() % 60 + 1;
        QString string;

        if(m_valueSaColor < 20 && m_valueSaColor >= 0){
            string = "green";
        } else if (m_valueSaColor < 40 && m_valueSaColor >= 20){
            string = "orange";
        } else if (m_valueSaColor <= 60 && m_valueSaColor >= 40){
            string = "red";
        }
        //qDebug() << "color: " << string;
        setSaStatusColor(string);
    }
}


