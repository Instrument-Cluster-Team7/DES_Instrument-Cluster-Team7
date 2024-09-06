#define ENCODER 3 //light detecting pin, connect D0 with 2
#define CIRCUMFERENCE 0.214 //enter in meter


volatile unsigned int counter = 0;
double rpm;
double speed_kmh;

 
void count(){
  counter++;
}

void setup() {
  // put your setup code here, to run once:

  //set pin status
  pinMode(ENCODER, INPUT);
  digitalWrite(ENCODER, HIGH);

  //interrupt to the PIN2, when rising edge count worksavrdude: ser_open(): can't open device "/dev/ttyACM0": No such file or directory
  int interrupt = (ENCODER == 2) ? 0 : 1;
  attachInterrupt(interrupt, count, RISING);

  //set serial transmission status
  Serial.begin(9600);
}

void loop() {
  // put your main code here, to run repeatedly:

  static uint32_t previousMillis;

  //calculate RPM and speed
   if (millis() - previousMillis >= 1000){
    rpm = (counter / 20.0) *60;
    speed_kmh = rpm * CIRCUMFERENCE *0.06;
    counter = 0;
    previousMillis += 1000;
   }


   //print speed on serial moniter
   Serial.print("RPM: ");
   Serial.println(rpm);
   Serial.print("Speed(km/h): ");
   Serial.println(speed_kmh);
}
