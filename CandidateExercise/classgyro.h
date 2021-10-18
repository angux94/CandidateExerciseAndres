#ifndef CLASSGYRO_H
#define CLASSGYRO_H

#include <QObject>
#include <QDebug>
#include <QTimer>

class ClassGYRO : public QObject
{
    Q_OBJECT

    // Main GYRO properties
    Q_PROPERTY(QString mgSstrength READ mgSstrength WRITE setMgSstrength NOTIFY mgSstrengthChanged)
    Q_PROPERTY(QString mgStatusColor READ mgStatusColor WRITE setMgStatusColor NOTIFY mgStatusColorChanged)

    // Backup GYRO properties
    Q_PROPERTY(QString bgSstrength READ bgSstrength WRITE setBgSstrength NOTIFY bgSstrengthChanged)
    Q_PROPERTY(QString bgStatusColor READ bgStatusColor WRITE setBgStatusColor NOTIFY bgStatusColorChanged)

public:
    explicit ClassGYRO(QObject *parent = nullptr);

    // Main GYRO functions
    QString mgSstrength();
    QString mgStatusColor();

    // Backup GYRO functions
    QString bgSstrength();
    QString bgStatusColor();

public slots:
    void delay();
    void globalTimer();

    // Main GYRO slots
    void setMgSstrength(QString);
    void setMgStatusColor(QString);
    void mgStrengthGen();
    void mgStatusGen();

    // Backup GYRO slots
    void setBgSstrength(QString);
    void setBgStatusColor(QString);
    void bgStrengthGen();
    void bgStatusGen();

signals:

    // Main GYRO signals
    void mgSstrengthChanged();
    void mgStatusColorChanged();

    // Backup GYRO signals
    void bgSstrengthChanged();
    void bgStatusColorChanged();

private:
    int m_time;

    // Main GYRO variables
    QString m_mgSstrength;
    QString m_mgStatusColor;
    double m_valueMgStrength;
    int m_valueMgColor;
    bool m_mgFlag;

    // Backup GYRO variables
    QString m_bgSstrength;
    QString m_bgStatusColor;
    double m_valueBgStrength;
    int m_valueBgColor;
    bool m_bgFlag;
};

#endif // CLASSGYRO_H
