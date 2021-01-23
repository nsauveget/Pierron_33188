# Un capteur de pression différentiel au format GROVE

TODO : mettre image et schéma

## Installation
Créer un nouveau repertoire nommé "Pierron_33188" dans le dossier "libraries" de votre dossier Arduino.
Y placer tous les fichiers.


## Usage
Pour utiliser la librairie dans votre propre projet, importer la avec  *Sketch > Import Library*.

Exemple :

```cpp
#include "Pierron_33188.h"

Pierron_33188 capteur = new Pierron_33188();
//Pierron_33188 capteur = new Pierron_33188(A0,5.0,0.0);

void setup(){
  Serial.begin(9600);
  Serial.println("Calibration du capteur.\nAppuyer sur une touche pour continuer.");
  while (Serial.available() == 0) {
    // Wait for User to Input Data
  }
  capteur.calibre();
}

void loop(){
  float p = capteur.read();
  Serial.print("Pression : ");
  Serial.print(p);
  Serial.println(" hPa");
  delay(1000);
}
```
