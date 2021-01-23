#ifndef PIERRON_33188_h
#define PIERRON_33188_h

#include <Arduino.h>

#define PIERRON_33188_VCC 5.0 //Tension d'alimentation par defaut
#define PIERRON_33188_GAIN 57.0 //Gain de l'ampli
#define PIERRON_33188_SENSITIVITY 1.2 //Sensibilité du capteur (mV/KPa)
#define PIERRON_33188_SENSITIVITY_VCC 3 //Vcc pour la sensibilité
#define PIERRON_33188_OFFSET 0.020 //Offset du capteur (V) par defaut
#define PIERRON_33188_ANALOG_RESOL 1023 //Resolution de l'entrée analogique 


class Pierron_33188
{
  public :
    Pierron_33188(int pin = A0, float vcc = PIERRON_33188_VCC, float offset = PIERRON_33188_OFFSET);
    float read(); // return pression en hPa
    void calibre();
  private :
    int _analog_input_pin;
    float _vcc;
    float _offset;
};

#endif
