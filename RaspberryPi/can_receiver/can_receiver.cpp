#include <iostream>
#include <cstring>
#include <sys/types.h>
#include <sys/socket.h>
#include <linux/can.h>
#include <linux/can/raw.h>
#include <net/if.h>
#include <sys/ioctl.h>
#include <unistd.h>

union DataUnion {
  float speed_kmh;
  u_int8_t bytes[4];
} rcv_data;

int main() {
    // Step 1: Create a CAN raw socket
    int socketCAN = socket(PF_CAN, SOCK_RAW, CAN_RAW);
    if (socketCAN < 0) {
        std::cerr << "Error while creating socket!" << std::endl;
        return -1;
    }

    // Step 2: Specify the CAN interface you want to use (can0)
    struct ifreq ifr;
    std::strcpy(ifr.ifr_name, "can0");
    if (ioctl(socketCAN, SIOCGIFINDEX, &ifr) < 0) {
        std::cerr << "Error getting interface index!" << std::endl;
        return -1;
    }

    // Step 3: Bind the socket to the CAN interface
    struct sockaddr_can addr;
    std::memset(&addr, 0, sizeof(addr));
    addr.can_family = AF_CAN;
    addr.can_ifindex = ifr.ifr_ifindex;

    if (bind(socketCAN, (struct sockaddr *)&addr, sizeof(addr)) < 0) {
        std::cerr << "Error in socket bind!" << std::endl;
        return -1;
    }

    // Step 4: Prepare to receive CAN messages
    struct can_frame frame;

    std::cout << "Listening for CAN messages on can0..." << std::endl;

    while (true) {
        int nbytes = read(socketCAN, &frame, sizeof(struct can_frame));
        if (nbytes < 0) {
            std::cerr << "Error reading CAN frame!" << std::endl;
            break;
        }

        //receive data from union

        for (int i = 0; i < 4; i++){
            rcv_data.bytes[i] = frame.data[i];
        }

        // Step 5: Process received CAN message
        std::cout << "Received CAN ID: " << std::hex << frame.can_id << std::endl;
        std::cout << "Data Length Code: " << std::dec << (int)frame.can_dlc << std::endl;
        std::cout << "Data: " << rcv_data.speed_kmh << std::endl;
    }

    // Step 6: Close the socket
    close(socketCAN);

    return 0;
}