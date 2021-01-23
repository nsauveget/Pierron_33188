#include "Pierron_33188.h"

//Constructeur
Pierron_33188::Pierron_33188(int pin, float vcc, float offset):  _analog_input_pin(pin), _vcc(vcc), _offset(offset){
  pinMode(_analog_input_pin, INPUT);
}

//Lecture de la pression en Hpa
float Pierron_33188::read(){
  int a0_raw = analogRead(_analog_input_pin);
  float a0_volt = a0_raw * _vcc / PIERRON_33188_ANALOG_RESOL;
  float a0_diff = a0_volt - _vcc / 2;
  float pression = (a0_diff - _offset) / PIERRON_33188_GAIN * 1000 / PIERRON_33188_SENSITIVITY * 10 / _vcc * PIERRON_33188_SENSITIVITY_VCC;
  return pression;
}

//Calibration de l'offset
void Pierron_33188::calibre(){
  int a0_raw = analogRead(_analog_input_pin);
  float a0_volt = a0_raw * _vcc / PIERRON_33188_ANALOG_RESOL;
  float a0_diff = a0_volt - _vcc / 2;
  _offset = a0_diff;
}
