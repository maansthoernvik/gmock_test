/**
 * Arduino Serial mock
 */
#ifndef SMARTCAR_H
#define SMARTCAR_H

#include <stdint.h>
#include <gmock/gmock.h>

class CarMock {
  public:
    MOCK_METHOD0(begin, void());
    MOCK_METHOD1(setSpeed, void(float));
    MOCK_METHOD1(setAngle, void(int));
    MOCK_METHOD0(getSpeed, float());
    MOCK_METHOD0(getAngle, int());
    MOCK_METHOD0(stop, void());
    MOCK_METHOD4(enableCruiseControl, void(float, float, float, unsigned short));
    MOCK_METHOD0(disableCruiseControl, void());
    MOCK_METHOD0(updateMotors, void());
    MOCK_METHOD1(go, void(int));
    MOCK_METHOD1(rotate, void(int));
    MOCK_METHOD2(setMotorSpeed, void(int, int));
    MOCK_METHOD0(cruiseControlEnabled, boolean());
};

/* Methods for instantiating and deleting the mock */
static CarMock* carMock = NULL;
CarMock* carMockInstance() {
  if(!carMock) {
    carMock = new CarMock();
  }
  return carMock;
}

void releaseCarMock() {
  if(carMock) {
    delete carMock;
    carMock = NULL;
  }
}
/* ------------------------------------------------ */

class Car {
  public:
//    Car(unsigned short shieldOrientation = 0);
//    Car(SteeringMotor *steering, ThrottleMotor *throttle);
    void begin(){
      carMock->begin();
    };
    // void begin(Odometer &encoder);
    // void begin(HeadingSensor &heading);
    // void begin(Odometer &encoder, HeadingSensor &heading);
    // void begin(Odometer &encoder1, Odometer &encoder2);
    // void begin(Odometer &encoder1, Odometer &encoder2, HeadingSensor &heading);
    void setSpeed(float speed){
      carMock->setSpeed(speed);
    };
    void setAngle(int degrees){
      carMock->setAngle(degrees);
    };
    float getSpeed(){
      carMock->getSpeed();
    };
    int getAngle(){
      carMock->getAngle();
    };
    void stop(){
      carMock->stop();
    };
    void enableCruiseControl(float Kp = 0, float Ki = 0, float Kd = 0, unsigned short frequency = 80){
      carMock->enableCruiseControl(Kp, Ki, Kd, frequency);
    };
    void disableCruiseControl(){
      carMock->disableCruiseControl();
    };
    void updateMotors(){
      carMock->updateMotors();
    };
    void go(int centimeters){
      carMock->go(centimeters);
    };
    void rotate(int degrees){
      carMock->rotate(degrees);
    };
    void setMotorSpeed(int leftMotorSpeed, int rightMotorSpeed){
      carMock->setMotorSpeed(leftMotorSpeed, rightMotorSpeed);
    };
    boolean cruiseControlEnabled(){
      carMock->cruiseControlEnabled();
    };
};


#endif // SMARTCAR_H