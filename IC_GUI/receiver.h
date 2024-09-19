#ifndef RECEIVER_H
#define RECEIVER_H

#include <QThread>
#include <sys/types.h>
#include <sys/socket.h>￣
#include <linux/can.h>
#include <linux/can/raw.h>
#include <net/if.h>
#include <sys/ioctl.h>
#include <unistd.h>

union DataUnion {
    float speed_kmh;
    char bytes[4];
};

class Receiver: public QThread
{

    Q_OBJECT
    Q_PROPERTY(float speedKmh READ getSpeed NOTIFY speedReceived)
    Q_PROPERTY(bool canStatus READ getConnection NOTIFY canConnected)

private:
    int socketCAN;
    struct ifreq ifr = ifr;
    struct sockaddr_can addr;
    DataUnion speed_data;
    bool canStatus = true;

public:
    static const int SUCCEDED = 0;
    static const int FAILED = -1;

    Receiver(QObject *parent = nullptr);
    ~Receiver();
    Receiver(const Receiver& rcv);
    Receiver operator=(const Receiver& rcv);
    float getSpeed() const {
        return speed_data.speed_kmh;
    }

    bool getConnection() const {
        return canStatus;
    }

    int initialize();
    void run();

signals:
    void speedReceived(float speedKmh);
    void canConnected(bool canStaus);
};

#endif // RECEIVER_H
