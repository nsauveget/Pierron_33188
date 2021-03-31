# Un capteur de pression différentiel au format GROVE

TODO : mettre image et schéma

## Installation
Créer un nouveau repertoire nommé "Pierron_33188" dans le dossier "libraries" de votre dossier Arduino (c://Documents/Arduino/librairies).
Y placer tous les fichiers en cliquant sur le bouton "Code" puis "Download ZIP".


## Usage
Pour utiliser la librairie dans votre propre projet, importez-la avec *Sketch > Import Library* (ou à partir de la version 1.813 de l'IDE Arduino avec *Croquis > Inclure une bibliothèque > Ajouter la bibliothèque ZIP*).

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
