#ifndef CLASSGPS_H
#define CLASSGPS_H

#include <QObject>
#include <QDebug>
#include <QTimer>

class ClassGPS : public QObject
{
    Q_OBJECT

    // Front GPS properties
    Q_PROPERTY(QString frontSstrength READ frontSstrength WRITE setfrontSstrength NOTIFY frontSstrengthChanged)
    Q_PROPERTY(QString frontStatusColor READ frontStatusColor WRITE setfrontStatusColor NOTIFY frontstatusColorChanged)

    // Rear GPS properties
    Q_PROPERTY(QString rearSstrength READ rearSstrength WRITE setRearSstrength NOTIFY rearSstrengthChanged)
    Q_PROPERTY(QString rearStatusColor READ rearStatusColor WRITE setRearStatusColor NOTIFY rearStatusColorChanged)

    // Starboard GPS properties
    Q_PROPERTY(QString sbSstrength READ sbSstrength WRITE setSbSstrength NOTIFY sbSstrengthChanged)
    Q_PROPERTY(QString sbStatusColor READ sbStatusColor WRITE setSbStatusColor NOTIFY sbStatusColorChanged)

    // Port GPS properties
    Q_PROPERTY(QString portSstrength READ portSstrength WRITE setPortSstrength NOTIFY portSstrengthChanged)
    Q_PROPERTY(QString portStatusColor READ portStatusColor WRITE setPortStatusColor NOTIFY portStatusColorChanged)


public:
    explicit ClassGPS(QObject *parent = nullptr);

    // Front GPS functions
    QString frontSstrength();
    QString frontStatusColor();

    // Rear GPS functions
    QString rearSstrength();
    QString rearStatusColor();

    // Starboard GPS functions
    QString sbSstrength();
    QString sbStatusColor();

    // Port GPS functions
    QString portSstrength();
    QString portStatusColor();

public slots:
    void delay();
    void globalTimer();

    // Front GPS slots
    void setfrontSstrength(QString);
    void setfrontStatusColor(QString);
    void frontStrengthGen();
    void frontStatusGen();

    // Rear GPS slots
    void setRearSstrength(QString);
    void setRearStatusColor(QString);
    void rearStrengthGen();
    void rearStatusGen();

    // Starboard GPS slots
    void setSbSstrength(QString);
    void setSbStatusColor(QString);
    void sbStrengthGen();
    void sbStatusGen();

    // Port GPS slots
    void setPortSstrength(QString);
    void setPortStatusColor(QString);
    void portStrengthGen();
    void portStatusGen();

signals:
    // Front GPS signals
    void frontSstrengthChanged();
    void frontstatusColorChanged();

    // Rear GPS signals
    void rearSstrengthChanged();
    void rearStatusColorChanged();

    // Starboard GPS signals
    void sbSstrengthChanged();
    void sbStatusColorChanged();

    // Port GPS signals
    void portSstrengthChanged();
    void portStatusColorChanged();

private:
    int m_time;

    // Front GPS variables
    QString m_frontSstrength;
    QString m_frontStatusColor;
    double m_valueFrontStrength;
    int m_valueFrontColor;
    bool m_frontFlag;

    // Rear GPS variables
    QString m_rearSstrength;
    QString m_rearStatusColor;
    double m_valueRearStrength;
    int m_valueRearColor;
    bool m_rearFlag;

    // Starboard GPS variables
    QString m_sbSstrength;
    QString m_sbStatusColor;
    double m_valueSbStrength;
    int m_valueSbColor;
    bool m_sbFlag;

    // Port GPS variables
    QString m_portSstrength;
    QString m_portStatusColor;
    double m_valuePortStrength;
    int m_valuePortColor;
    bool m_portFlag;

};

#endif // CLASSGPS_H
