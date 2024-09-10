#ifndef RECEIVER_H
#define RECEIVER_H

#include <QThread>
#include <sys/types.h>
#include <sys/socket.h>
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

private:
    int socketCAN;
    struct ifreq ifr = ifr;
    struct sockaddr_can addr;
    DataUnion speed_data;

public:
    static const int SUCCEDED = 0;
    static const int FAILED = -1;

    Receiver(QObject *parent = nullptr);
    ~Receiver();
    Receiver(const Receiver& rcv);
    Receiver operator=(const Receiver& rcv);

    int initialize();
    void run();

signals:
    void speedReceived(int speed);
};

#endif // RECEIVER_H
