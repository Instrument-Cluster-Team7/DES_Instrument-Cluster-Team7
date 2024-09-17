
#include <mcp_can.h>
#include <SPI.h>

// the cs pin of the version after v1.1 is default to D9
// v0.9b and v1.0 is default D10

const int SPI_CS_PIN = 9;

//set the variables of speed sensor
#define ENCODER 3 //light detecting pin, connect D0 with 3
#define CIRCUMFERENCE 0.214 //enter in meter
#define PERIOD 0.1

volatile unsigned int counter = 0;
double rpm;

void count(){
  counter++;
}

/* Union that can devide 4byte data */
union DataUnion {
  float speed_kmh;
  byte bytes[4];
} data;

MCP_CAN CAN(SPI_CS_PIN);                                    // Set CS pin

void setup()
{
    Serial.begin(115200);
    
    while (CAN_OK != CAN.begin(MCP_ANY, CAN_500KBPS, MCP_16MHZ))              // init can bus : baudrate = 500k
    {
        Serial.println("CAN BUS Shield init fail");
        Serial.println(" Init CAN BUS Shield again");
        delay(100);
    }
    
    Serial.println("CAN BUS Shield init ok!");
    CAN.setMode(MCP_NORMAL);

    //set pin status
    pinMode(ENCODER, INPUT);
    digitalWrite(ENCODER, HIGH);

    //interrupt to the PIN2, when rising edge count worksavrdude: ser_open(): can't open device "/dev/ttyACM0": No such file or directory
    int interrupt = (ENCODER == 2) ? 0 : 1;
    attachInterrupt(interrupt, count, RISING);
}


void loop()
{
    static uint32_t previousMillis;
  
    if (millis() - previousMillis >= 1000 *PERIOD){
        rpm = (counter / 20.0) * 60 * PERIOD;
        data.speed_kmh = rpm * CIRCUMFERENCE *0.06;
        
        counter = 0;
        previousMillis += 1000 * PERIOD;
        
        Serial.print("RPM: ");
        Serial.println(data.speed_kmh);

        if ( CAN.sendMsgBuf(0x00, 0, 4, data.bytes) == CAN_OK){
          Serial.println("Succesfully sent!");
        }
        else{
          Serial.println("failed!");
        }
   }                    // send data per 100ms
}
// END FILE
