#ifndef CLASSCOMPASS_H
#define CLASSCOMPASS_H

#include <QObject>
#include <QDebug>
#include <QTimer>

class ClassCOMPASS : public QObject
{
    Q_OBJECT

    // Compass 1 properties
    Q_PROPERTY(QString c1Sstrength READ c1Sstrength WRITE setC1Sstrength NOTIFY c1SstrengthChanged)
    Q_PROPERTY(QString c1StatusColor READ c1StatusColor WRITE setC1StatusColor NOTIFY c1StatusColorChanged)

    // Compass 2 properties
    Q_PROPERTY(QString c2Sstrength READ c2Sstrength WRITE setC2Sstrength NOTIFY c2SstrengthChanged)
    Q_PROPERTY(QString c2StatusColor READ c2StatusColor WRITE setC2StatusColor NOTIFY c2StatusColorChanged)

    // Compass 3 properties
    Q_PROPERTY(QString c3Sstrength READ c3Sstrength WRITE setC3Sstrength NOTIFY c3SstrengthChanged)
    Q_PROPERTY(QString c3StatusColor READ c3StatusColor WRITE setC3StatusColor NOTIFY c3StatusColorChanged)

    // Compass 4 properties
    Q_PROPERTY(QString c4Sstrength READ c4Sstrength WRITE setC4Sstrength NOTIFY c4SstrengthChanged)
    Q_PROPERTY(QString c4StatusColor READ c4StatusColor WRITE setC4StatusColor NOTIFY c4StatusColorChanged)


public:
    explicit ClassCOMPASS(QObject *parent = nullptr);

    // Compass 1 functions
    QString c1Sstrength();
    QString c1StatusColor();

    // Compass 2 functions
    QString c2Sstrength();
    QString c2StatusColor();

    // Compass 3 functions
    QString c3Sstrength();
    QString c3StatusColor();

    // Compass 4 functions
    QString c4Sstrength();
    QString c4StatusColor();

public slots:
    void delay();
    void globalTimer();

    // Compass 1 slots
    void setC1Sstrength(QString);
    void setC1StatusColor(QString);
    void c1StrengthGen();
    void c1StatusGen();

    // Compass 2 slots
    void setC2Sstrength(QString);
    void setC2StatusColor(QString);
    void c2StrengthGen();
    void c2StatusGen();

    // Compass 3 slots
    void setC3Sstrength(QString);
    void setC3StatusColor(QString);
    void c3StrengthGen();
    void c3StatusGen();

    // Compass 4 slots
    void setC4Sstrength(QString);
    void setC4StatusColor(QString);
    void c4StrengthGen();
    void c4StatusGen();

signals:

    // Compass 1 signals
    void c1SstrengthChanged();
    void c1StatusColorChanged();

    // Compass 2 signals
    void c2SstrengthChanged();
    void c2StatusColorChanged();

    // Compass 3 signals
    void c3SstrengthChanged();
    void c3StatusColorChanged();

    // Compass 4 signals
    void c4SstrengthChanged();
    void c4StatusColorChanged();

private:
    int m_time;

    // Compass 1 variables
    QString m_c1Sstrength;
    QString m_c1StatusColor;
    double m_valueC1Strength;
    int m_valueC1Color;
    bool m_c1Flag;

    // Compass 2 variables
    QString m_c2Sstrength;
    QString m_c2StatusColor;
    double m_valueC2Strength;
    int m_valueC2Color;
    bool m_c2Flag;

    // Compass 3 variables
    QString m_c3Sstrength;
    QString m_c3StatusColor;
    double m_valueC3Strength;
    int m_valueC3Color;
    bool m_c3Flag;

    // Compass 4 variables
    QString m_c4Sstrength;
    QString m_c4StatusColor;
    double m_valueC4Strength;
    int m_valueC4Color;
    bool m_c4Flag;

};

#endif // CLASSCOMPASS_H
