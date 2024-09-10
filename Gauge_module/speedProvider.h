#ifndef SPEEDPROVIDER_H
#define SPEEDPROVIDER_H

#include <QObject>
#include "receiver.h"
#include <cstdlib>
#include <ctime>

class SpeedProvider : public QObject
{
    Q_OBJECT
    Q_PROPERTY(float speedValue READ speedValue NOTIFY speedChanged)

public:
    explicit SpeedProvider(QObject *parent = nullptr)
        : QObject(parent), m_speedValue(0)
    {

        Receiver * rcv = new Receiver();
        if (rcv->initialize() == Receiver::SUCCEDED){
            QObject::connect(rcv, &Receiver::speedReceived, this, &SpeedProvider::speedChange);
            rcv->start();
        }
    }

    int speedValue() const
    {
        return m_speedValue;
    }

    int minSpeed() const
    {
        return m_minSpeed;
    }

    int maxSpeed() const
    {
        return m_maxSpeed;
    }

    void setMinSpeed(int minSpeed)
    {
        if(minSpeed != m_minSpeed){
            m_minSpeed = minSpeed;
            emit minSpeedChanged();
        }
    }

    void setMaxSpeed(int maxSpeed)
    {
        if(maxSpeed != m_maxSpeed){
            m_maxSpeed = maxSpeed;
            emit maxSpeedChanged();
        }
    }

signals:
    void speedChanged();
    void minSpeedChanged();
    void maxSpeedChanged();

private slots:
    void speedChange(float speed){
        if (m_speedValue != speed){
            m_speedValue = speed;
            emit speedChanged();
        }
    }

    void generateSpeed()
    {
        if(m_minSpeed < m_maxSpeed){
            m_speedValue = m_minSpeed + std::rand() % (m_maxSpeed - m_minSpeed + 1);
        }
        emit speedChanged();  // QML에 값이 변경되었음을 알림
    }

private:
    float m_speedValue;  // 현재 속도 값
    int m_minSpeed;
    int m_maxSpeed;
};

#endif // SPEEDPROVIDER_H
