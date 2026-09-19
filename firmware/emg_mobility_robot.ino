#include <AFMotor.h>
#include <SoftwareSerial.h>

// Bluetooth
SoftwareSerial BT(2, 3);

// Motors
AF_DCMotor m1(1);
AF_DCMotor m2(2);
AF_DCMotor m3(3);
AF_DCMotor m4(4);

// Sensor
int sensorPin = A0;
int value = 0;
int threshold = 600;

void setup() {
  Serial.begin(9600);
  BT.begin(9600);

  m1.setSpeed(200);
  m2.setSpeed(200);
  m3.setSpeed(200);
  m4.setSpeed(200);
}

void loop() {
  value = analogRead(sensorPin);

  BT.print("VALUE: ");
  BT.println(value);

  if (value > threshold) {
    m1.run(FORWARD);
    m2.run(FORWARD);
    m3.run(FORWARD);
    m4.run(FORWARD);

    BT.println("FORWARD");
  } else {
    m1.run(RELEASE);
    m2.run(RELEASE);
    m3.run(RELEASE);
    m4.run(RELEASE);

    BT.println("STOP");
  }

  delay(300);
}
