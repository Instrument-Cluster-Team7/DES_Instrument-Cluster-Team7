import can

can_interface = 'can0'
bus = can.Bus(channel=can_interface, interface='socketcan')  # Use 'channel' for the interface name (can0)

while True:
    message = bus.recv(1.0)  # Timeout in seconds.
    if message is None:
        print('Timeout occurred, no message.')
    else:
        print(message)
