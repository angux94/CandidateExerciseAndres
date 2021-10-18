#ifndef CLASSANEMOMETER_H
#define CLASSANEMOMETER_H

#include <QObject>
#include <QDebug>
#include <QTimer>

class ClassANEMOMETER : public QObject
{
    Q_OBJECT

    // Primary Anemometer Properties
    Q_PROPERTY(QString paSstrength READ paSstrength WRITE setPaSstrength NOTIFY paSstrengthChanged)
    Q_PROPERTY(QString paStatusColor READ paStatusColor WRITE setPaStatusColor NOTIFY paStatusColorChanged)

    // Secondary Anemometer Properties
    Q_PROPERTY(QString saSstrength READ saSstrength WRITE setSaSstrength NOTIFY saSstrengthChanged)
    Q_PROPERTY(QString saStatusColor READ saStatusColor WRITE setSaStatusColor NOTIFY saStatusColorChanged)

public:
    explicit ClassANEMOMETER(QObject *parent = nullptr);

    // Primary Anemometer Functions
    QString paSstrength();
    QString paStatusColor();

    // Secondary Anemometer Functions
    QString saSstrength();
    QString saStatusColor();

public slots:
    void delay();
    void globalTimer();

    // Primary Anemometer slots
    void setPaSstrength(QString);
    void setPaStatusColor(QString);
    void paStrengthGen();
    void paStatusGen();

    // Secondary Anemometer slots
    void setSaSstrength(QString);
    void setSaStatusColor(QString);
    void saStrengthGen();
    void saStatusGen();

signals:
    // Primary Anemometer signals
    void paSstrengthChanged();
    void paStatusColorChanged();

    // Secondary Anemometer signals
    void saSstrengthChanged();
    void saStatusColorChanged();

private:
    int m_time;

    // Primary Anemometer variables
    QString m_paSstrength;
    QString m_paStatusColor;
    double m_valuePaStrength;
    int m_valuePaColor;
    bool m_paFlag;

    // Secondary Anemometer variables
    QString m_saSstrength;
    QString m_saStatusColor;
    double m_valueSaStrength;
    int m_valueSaColor;
    bool m_saFlag;

};

#endif // CLASSANEMOMETER_H
