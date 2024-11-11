# DES Instrument Cluster Team7

## Result Video
<video controls src="https://private-user-images.githubusercontent.com/67433199/381587579-0524db46-d54a-4b5f-ae91-c57c40d0804c.mp4?jwt=eyJhbGciOiJIUzI1NiIsInR5cCI6IkpXVCJ9.eyJpc3MiOiJnaXRodWIuY29tIiwiYXVkIjoicmF3LmdpdGh1YnVzZXJjb250ZW50LmNvbSIsImtleSI6ImtleTUiLCJleHAiOjE3MzAyOTgxOTcsIm5iZiI6MTczMDI5Nzg5NywicGF0aCI6Ii82NzQzMzE5OS8zODE1ODc1NzktMDUyNGRiNDYtZDU0YS00YjVmLWFlOTEtYzU3YzQwZDA4MDRjLm1wND9YLUFtei1BbGdvcml0aG09QVdTNC1ITUFDLVNIQTI1NiZYLUFtei1DcmVkZW50aWFsPUFLSUFWQ09EWUxTQTUzUFFLNFpBJTJGMjAyNDEwMzAlMkZ1cy1lYXN0LTElMkZzMyUyRmF3czRfcmVxdWVzdCZYLUFtei1EYXRlPTIwMjQxMDMwVDE0MTgxN1omWC1BbXotRXhwaXJlcz0zMDAmWC1BbXotU2lnbmF0dXJlPWY4OWJkYmYwYTNkNTNmNzlhMDdjYTQwZDljZTExZTU3ZDU3YWU3MmQ1MDlhNTZlZGNkZjcyZjg1NjcxYTUwNDAmWC1BbXotU2lnbmVkSGVhZGVycz1ob3N0In0.QA4t4eSsUbVcEGkMwZTkGuq1OuwI9YamsV-Cwkd7V-A" title="success screen"></video>

<video controls src="https://private-user-images.githubusercontent.com/67433199/381587149-f11bfdf7-cd6d-470e-a7b9-b82a95cdbfc4.mp4?jwt=eyJhbGciOiJIUzI1NiIsInR5cCI6IkpXVCJ9.eyJpc3MiOiJnaXRodWIuY29tIiwiYXVkIjoicmF3LmdpdGh1YnVzZXJjb250ZW50LmNvbSIsImtleSI6ImtleTUiLCJleHAiOjE3MzAyOTgyMzIsIm5iZiI6MTczMDI5NzkzMiwicGF0aCI6Ii82NzQzMzE5OS8zODE1ODcxNDktZjExYmZkZjctY2Q2ZC00NzBlLWE3YjktYjgyYTk1Y2RiZmM0Lm1wND9YLUFtei1BbGdvcml0aG09QVdTNC1ITUFDLVNIQTI1NiZYLUFtei1DcmVkZW50aWFsPUFLSUFWQ09EWUxTQTUzUFFLNFpBJTJGMjAyNDEwMzAlMkZ1cy1lYXN0LTElMkZzMyUyRmF3czRfcmVxdWVzdCZYLUFtei1EYXRlPTIwMjQxMDMwVDE0MTg1MlomWC1BbXotRXhwaXJlcz0zMDAmWC1BbXotU2lnbmF0dXJlPTQ3MzIxZWExYjg0NmY3YTUwMGE3ZjAxOGNhMDA5NGQ5MDAxZTJlYThkZGNiOGUwZGViOTdjYmMxOWQ4M2YzZDQmWC1BbXotU2lnbmVkSGVhZGVycz1ob3N0In0.BN6e-IaKjj5CN5ihs-mVtHdztvnQmcvMoxfKuhhKt_E
" title="success shown"></video>


## Introduction

The PiRacer instrument cluster Qt application project is aimed at creating a real-time speedometer for a PiRacer car. The speedometer GUI of PiRacer car displays real-time speed data from a speed sensor via CAN bus, and it shows the battery level of PiRacer via I2C bus between PiRacer and Raspberry Pi. [Here is the detailed explanation of our goal of this project.](https://github.com/SEA-ME/DES_Instrument-Cluster)

---

## Structure

- **Receiving speed value by CAN protocol:** Arduino sends the speed value (km/h, float type) gained by speed sensor using the CAN protocol, and Raspberry Pi receives it and print on GUI.
- **Receiving given battery by I2C bus:** The PiRacer provides various value to the Raspberry Pi by I2C communication: voltage, current, power, steering, etc. After receiving the speed data by I2C bus, Raspberry Pi calculates the remained battery percentage.
- **GUI:** the GUI on the display is designed by QT Quick Framework, which includes the declarative scripting language QML and data processing library written and processed by C++.
- **Docker Container:** All code in the Raspberry Pi is wrapped in the Docker container, to manage the code designed from the other environment to the Raspberry Pi.

---

## Code explanation - Arduino

This code in the Arduino UNO reads data from a speed sensor, calculates speed, and sends the speed value over a CAN bus using the MCP2515 CAN bus module. Here's a very short summary:

1. **Interrupt-based Speed Sensing**: The code uses an interrupt to increment a counter every time a revolution is detected by the sensor. The interrupt occurs whenever slot in the rotor is detected. When interrupt is detected 20 times, it indicates that the wheel took a turn once.
2. **Speed Calculation**: Every second, the speed (cm/s) is calculated by RPM, which is gained the number of instrrupt occured per second. Suppose the interrupts per period(p) as n. Here is formula: 
    
    $$
    RPM=\frac{60n}{20P}
    v(cm/s) = \frac{RPM * 2\pi r * 100}{60}
    $$
    
3. **CAN Bus Communication**: The calculated RPM is sent over the CAN bus in 4 bytes using the MCP2515 module. The union is used to send and receive the float type variable as a form of 4-byte data in CAN module.

---

## Code explanation - Raspberry Pi

This project is divided according to modules. There is a module that receives CAN data, a module that reads battery data, and a module that implements a GUI. The main file integrates and manages all modules.

### CAN Receiver(receiver.h, receiver.cpp)

It receive the 4 bytes data from the CAN bus of MCP2515 module.  The union is used to receive the 4-byte data in CAN message as a form of float type. Whenever data is received, signal connected to the GUI is emitted. 

The received speed data is smoothed by the EMA(Exponential Moving Average) filter with smoothing factor α=0.3.

$$
v_{n} = \alpha u + (1- \alpha)v_{n-1}
$$

### Battery Provider

**Used Battery : 3 Sanyo 18650 2600mAh lithium-ion batteries**

- Sanyo 18650 Lithium-ion battery’s State of Charge needs a complex function. Because the motherboard of PiRacer only has the current voltage of battery. So we need to mapping the voltage to percentage.

| Voltage (x3 cells) [V] | Battery Level [%] |
| --- | --- |
| 12.6 | 100 |
| 12.3 | 91 |
| 12.0 | 79 |
| 11.7 | 62 |
| 11.4 | 42 |
| 11.1 | 12 |
| 10.8 | 2 |
| 10.5 | 0 |

→ In this link[[https://lygte-info.dk/info/BatteryChargePercent UK.html](https://lygte-info.dk/info/BatteryChargePercent%20UK.html)], you can check the measurement of estimating remaining capacity in Lithium-ion batteries. The battery voltage (from 3.5V to 4.2V for each cell) is used to represent the battery charge from 0% to 100%. Since we have three 18650 cells in series, the total voltage ranges from 10.5V to 12.6V, with the corresponding percentages as follow

**How to calculate battery percentage**

```cpp
int calculateBatteryPercentage(double voltage) {
    if (voltage >= MAX_VOLTAGE) {
        return 100;
    } else if (voltage <= MIN_VOLTAGE) {
        return 0;
    } else {
        return round(((voltage - MIN_VOLTAGE) / (MAX_VOLTAGE - MIN_VOLTAGE)) * 100);
    }
}
```

$$
y(x)=−25.6269⋅x3+887.9706⋅x2−10180.5203⋅x+38661.8396
$$

We decide to use this formula (linear transformation) to convert the voltage within a certain range into a percentage representing the battery level. According to the paper[[https://lygte-info.dk/info/BatteryChargePercent UK.html](https://lygte-info.dk/info/BatteryChargePercent%20UK.html)], we can also use a cubic polynomial to approximate the discharge curve to reflect the nonlinear characteristics of battery discharge. However, we used the above method for the following reasons. 1. Simplicity of calculation, 2. Since the voltage range is small, it is expected that no large errors will occur even if a linear model is used, 3. Since the remaining battery capacity must be quickly calculated and reflected in the UI, a linear method that ensures constant changes in remaining battery capacity use transformation.

**How to get the data**

From Raspberry pi4, we can communicate directly with the I2C device. 

![image.png](https://private-user-images.githubusercontent.com/67433199/381590592-9c2ce56f-bc0a-4508-a35f-9804fb90d4d1.png?jwt=eyJhbGciOiJIUzI1NiIsInR5cCI6IkpXVCJ9.eyJpc3MiOiJnaXRodWIuY29tIiwiYXVkIjoicmF3LmdpdGh1YnVzZXJjb250ZW50LmNvbSIsImtleSI6ImtleTUiLCJleHAiOjE3MzAyOTg0MjMsIm5iZiI6MTczMDI5ODEyMywicGF0aCI6Ii82NzQzMzE5OS8zODE1OTA1OTItOWMyY2U1NmYtYmMwYS00NTA4LWEzNWYtOTgwNGZiOTBkNGQxLnBuZz9YLUFtei1BbGdvcml0aG09QVdTNC1ITUFDLVNIQTI1NiZYLUFtei1DcmVkZW50aWFsPUFLSUFWQ09EWUxTQTUzUFFLNFpBJTJGMjAyNDEwMzAlMkZ1cy1lYXN0LTElMkZzMyUyRmF3czRfcmVxdWVzdCZYLUFtei1EYXRlPTIwMjQxMDMwVDE0MjIwM1omWC1BbXotRXhwaXJlcz0zMDAmWC1BbXotU2lnbmF0dXJlPWQwOGNjYTBhZWZkNjM5ZWFkNWUxYzc3OGUwNGQ3NDc0MGM3MzFmOTc2OGYzMjk5NWQyYzllMTU1ODMzZTgwNmQmWC1BbXotU2lnbmVkSGVhZGVycz1ob3N0In0.VbIucjZr1kkFlY2dwXaqly_IcOHQWtR1jHwOWloCtl8)

INA219 Power Monitor is a device that can monitor current, voltage, power consumption and more via I2C communication. Set the I2C slave address of INA219 to **0x41**, use smbus to read the overcurrent and outputs the battery value.

**Set animation**

The battery percentage calculation ensures that as the voltage drops from 12.6V to 10.5V, the battery level will correspondingly decrease from 100% to 0%, providing a smooth visual representation on the gauge in our Qt application. The smoothing mechanism (using a deque to average the latest 10 values) helps stabilize rapid fluctuations in the displayed percentage.

---

## Code explanation - GUI

- Dial.qml
    
    This code represents the background of speedometer. The scale is drawn using the Canvas function.
    
- Needle.qml
    
    Needle is made using Rectangle function. Animation is applied to rotation to make the needle move smoothly according to the speed value.
    
- SpeedText.qml
    
    This component represents speed data. Text changes according to the speed value. An animation is implemented so that the value changes step by step.
    
- Clock.h
    
    The current time is expressed through QTimer. Time is updated every second. The timeChanged() signal is generated by the updateTime() slot to update the time.
    
- main.qml
    
    Just for placing the components and images. It was arranged taking into account the relationship between elements.
    
- main.cpp
    
    This code manages all of data generated on this project. It generates objects related to Clock, Speed, Battery and Running rate. The objects are connected with engines and load them. And it contains the part that opens the I2C_BUS to get the data
    
- get_battery.h & get_battery.cpp
    
    Using the I2C protocol send the register address to the I2C device, reads two bytes of data (buf[2]), combines the two bytes into a 16-bit value. And then read the Voltage, Current and Power to convert it into percentage. 
    
- battery_gauge.h & battery_gauge.cpp
    
    Set the speedometer using QQuickPaintedItem. It makes possible to use the QPainter with QML. This code represents the gauge of PiRacer’s battery percentage.
    

---

## Code explanation - Docker

All code in the Raspberry Pi is wrapped in the Docker container, to manage the code to the Raspberry Pi, which has different environment from the development environment or QT. It provides same libraries, version, etc.

## Stack

<center>
<table>
  <tr>
    <td align="center" width="140px">
      <a href="https://www.linux.org/">
        <img src="https://www.kernel.org/theme/images/logos/tux.png" width="48" height="48" alt="linux" />
      </a>
      <br />Linux
    </td>
    <td align="center" width="140px">
      <a href="https://www.qt.io/">
        <img src="https://www.qt.io/hubfs/Qt-logo-neon-small.png" width="60" height="40" alt="Grafana" />
      </a>
      <br />QT Quick
    <td align="center" width="140px">
      <a href="https://isocpp.org/">
        <img src="https://isocpp.org/assets/images/cpp_logo.png" width="48" height="48" alt="c++" />
      </a>
      <br />C++
    </td>
  </tr>
  <tr>
    <td align="center" width="140px">
      <a href="https://www.raspberrypi.com/">
        <img src="https://upload.wikimedia.org/wikipedia/de/thumb/c/cb/Raspberry_Pi_Logo.svg/1200px-Raspberry_Pi_Logo.svg.png" width="40" height="48" alt="raspberrypi" />
      </a>
      <br />Raspberry Pi
    </td>
    <td align="center" width="140px">
      <a href="https://www.arduino.cc/">
        <img src="https://static-00.iconduck.com/assets.00/apps-arduino-icon-2048x2048-42m5bo99.png" width="48" height="48" alt="arduino" />
      </a>
      <br />Arduino
    </td>
    </td>
    <td align="center" width="140px">
      <a href="https://www.docker.com/">
        <img src="https://www.svgrepo.com/show/349342/docker.svg" width="48" height="48" alt="docker" />
      </a>
      <br />Docker
    </td>
  </tr>
</table>
</center>

## Contributors
<table>

  <tr>
    <td align="center">
      <a href="https://github.com/jo49973477>">
        <img src="https://github.com/jo49973477.png" width="150px;" alt="Yeongyoo Jo"/>
        <br />
        <sub><b>Yeongyoo Jo</b></sub>
      </a>
      <br />
      <a href="https://github.com/jo49973477"><img src="https://img.shields.io/badge/GitHub-jo49973477-blue?logo=github" alt="GitHub Badge" /></a>
      <br />
    </td>
    <td align="center">
      <a href="https://github.com/iznue">
        <img src="https://github.com/iznue.png" width="150px;" alt="Eunji Lee"/>
        <br />
        <sub><b>Eunji Lee</b></sub>
      </a>
      <br />
      <a href="https://github.com/iznue"><img src="https://img.shields.io/badge/GitHub-iznue-blue?logo=github" alt="GitHub Badge" /></a>
      <br />
    </td>
    <td align="center">
      <a href="https://github.com/junspring">
        <img src="https://github.com/junspring.png" width="150px;" alt="Junbeom Jung"/>
        <br />
        <sub><b>Junbeom Jung</b></sub>
      </a>
      <br />
      <a href="https://github.com/junspring"><img src="https://img.shields.io/badge/GitHub-junspring-blue?logo=github" alt="GitHub Badge" /></a>
      <br />
    </td>
    <td align="center">
      <a href="https://github.com/YEOHANBIN">
        <img src="https://github.com/YEOHANBIN.png" width="150px;" alt="Hanbin Yeo"/>
        <br />
        <sub><b>Hanbin Yeo</b></sub>
      </a>
      <br />
      <a href="https://github.com/YEOHANBIN"><img src="https://img.shields.io/badge/GitHub-YEOHANBIN-blue?logo=github" alt="GitHub Badge" /></a>
      <br />
      <td align="center">
      <a href="https://github.com/Ziyad129-ux">
        <img src="https://github.com/Ziyad129-ux.png" width="150px;" alt="Ziyad"/>
        <br />
        <sub><b>Ziyad</b></sub>
      </a>
      <br />
      <a href="https://github.com/Ziyad129-ux"><img src="https://img.shields.io/badge/GitHub-Ziyad129-blue?logo=github" alt="GitHub Badge" /></a>
      <br />
    </td>
    
  </tr>
</table>
