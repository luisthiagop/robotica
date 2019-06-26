#include "OurStepper.h"

OurStepper::OurStepper(
  uint8_t interface, 
  uint8_t pin1, 
  uint8_t pin2, 
  uint8_t pin3, 
  uint8_t pin4, 
  bool enable) : 
  AccelStepper(interface, pin1, pin2, pin3, pin4, enable) {} 

void OurStepper::setMicroStep(int value) {
  microSteps = value;
}

void OurStepper::setStepsPerRevolution(int value) {
  stepsPerRevolution = value;
}

void OurStepper::setDistancePerRevolution(float value) {
  distancePerRevolution = value;
}

float OurStepper::getCurrentPositionDistance() {
  return currentPosition() / (microSteps * stepsPerRevolution / distancePerRevolution);
}

void OurStepper::moveToDistance(float value) {
  moveTo(value * microSteps * stepsPerRevolution / distancePerRevolution);
}

void OurStepper::runToNewDistance(float value) {
    moveToDistance(value);
    runToPosition();
}

void OurStepper::setAnglePerRevolution(float value) {
  anglePerRevolution = value;
}

void OurStepper::moveToAngle(float value) {
  moveTo(value * microSteps * stepsPerRevolution / anglePerRevolution);
}

void OurStepper::runToNewAngle(float value) {
    moveToAngle(value);
    runToPosition();
}
