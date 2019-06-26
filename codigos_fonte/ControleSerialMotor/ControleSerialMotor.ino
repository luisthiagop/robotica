#include <AccelStepper.h>

boolean infoCompleta = false;
int deslocamentoX = 0;

AccelStepper stepperX(AccelStepper::DRIVER, 2, 0); // (dir, step) Defaults to AccelStepper::DRIVER (2 pins) on 2, 3

void setup() {
  Serial.begin(9600);
  stepperX.setMaxSpeed(250);
  stepperX.setAcceleration(2000);
}

void loop() {
  ESPserialEvent();
  if (infoCompleta) {
    stepperX.moveTo(deslocamentoX);
    infoCompleta = false;
  }
  if (stepperX.distanceToGo() != 0) {
    stepperX.run();
  }
}

void ESPserialEvent() {
  while (Serial.available()) {
    int velocidade,angulo=0; 
    char c = Serial.read();
    switch (c)
    {
      case 'a':
        angulo = Serial.parseInt();
        deslocamentoX += (angulo*200)/360;
        Serial.print("Deslocamento X: ");
        Serial.println(deslocamentoX);
        Serial.print("Angulo: ");
        Serial.println(angulo);
        break;
      case 'x':
        deslocamentoX += Serial.parseInt();
        Serial.print("Deslocamento X: ");
        Serial.println(deslocamentoX);
        break;
      case 'v':
        velocidade = Serial.parseInt();
        stepperX.setMaxSpeed(velocidade);
        Serial.print("Velocidade: ");
        Serial.println(velocidade);
        break;
      case 'h':
        deslocamentoX = 0;
        break;
    }
    infoCompleta = c == '\n';
  }
}
