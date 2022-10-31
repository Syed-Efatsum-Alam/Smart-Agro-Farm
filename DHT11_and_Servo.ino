#include <SimpleDHT.h>
#include <Servo.h>

//Declare the servo pin
int servoPin = 7;



// for DHT11, 
//      VCC: 5V or 3V
//      GND: GND
//      DATA: 2
int pinDHT11 = 4;

Servo Servo1;
SimpleDHT11 dht11(pinDHT11);

void setup() {
    // start working...
  Servo1.attach(servoPin);
  Servo1.write(180);
  Serial.begin(9600);
  Serial.println("Temp Data: ");
}

void loop() {
 
  
  
  // read without samples.
  byte temperature = 0;
  byte humidity = 0;
  int err = SimpleDHTErrSuccess;
  if ((err = dht11.read(&temperature, &humidity, NULL)) != SimpleDHTErrSuccess) {
    Serial.print("Read DHT11 failed, err="); Serial.print(SimpleDHTErrCode(err));
    Serial.print(","); Serial.println(SimpleDHTErrDuration(err)); delay(1000);
    return;
  }
  
 
  Serial.print((int)temperature); Serial.print(" *C, "); 
  Serial.print((int)humidity); Serial.println(" H");
  if((int)temperature>20){
      Servo1.write(0);
      delay(100);
      
      Servo1.write(90);
      delay(100);

      Servo1.write(180);
      delay(1000);

      Servo1.write(90);
      delay(100);

      Servo1.write(0);
      delay(100);
  }
}
