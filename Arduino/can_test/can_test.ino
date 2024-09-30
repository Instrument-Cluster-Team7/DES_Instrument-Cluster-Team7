#include <AA_MCP2515.h>
#include <SPI.h>

/* constants setting related to speed sensor */
#define ENCODER 2 //light detecting pin, connect D0 with 2
#define CIRCUMFERENCE 0.214 //enter in meter
volatile unsigned int counter = 0;
int rpm;

/* constants setting related to CAN communication */
const CANBitrate::Config CAN_BITRATE = CANBitrate::Config_8MHz_500kbps;
#define CAN_CS 10
#define CAN_INT 3
#define CAN_ID 0x100

CANConfig config(CAN_BITRATE, CAN_CS, CAN_INT);
CANController CAN(config);

/* Union that can devide 4byte data */
union DataUnion {
  float speed_kmh;
  byte bytes[4];
} data;


void count() {
  counter++;
}

void setup() {
  // put your setup code here, to run once:

  //set pin status about Speed Detector
  pinMode(ENCODER, INPUT);
  digitalWrite(ENCODER, HIGH);

  //set pin status about MPC2515
  Serial.begin(115200);  
  while(CAN.begin(CANController::Mode::Normal) != CANController::OK) {
    Serial.println("CAN begin FAIL - delaying for 1 second");
    delay(1000);
  }
  Serial.println("CAN begin OK");

}

void loop() {
  // put your main code here, to run repeatedly:

  static uint32_t previousMillis;


  if (millis() - previousMillis >= 1000) {
    //calculate RPM and speed
    rpm = (counter / 20) * 60;
    data.speed_kmh = rpm * CIRCUMFERENCE * 0.06;
    counter = 0;
    previousMillis += 1000;

    //send 4 byte data
    CAN.write(CAN_ID, data.bytes, 4);
  }


  //print speed on serial moniter
  Serial.print("RPM: ");
  Serial.println(rpm);
  Serial.print("Speed(km/h): ");
  Serial.println(data.speed_kmh);
}
