#include <cmath>
#include <fstream>
#include <iostream>
#include <string>
// header file for own complex number class
#include "complex.h"
using namespace std;

int main() {
  
  //Variablen
  MyComplex z0, z1, c0, z_ll, z_ur;
  double x0, y0, x_m, y_m, delta_x, delta_y, tmp[2];
  int nr_iter, n_x_max, n_y_max, n_exp, n_max_iter, r_conv;
  string filename;
 
//Variablen einlesen
  //"nr_inter";
  cin >> nr_iter;
  //"Wertebereich";
  cin >> x0 >> y0 >> x_m >> y_m;
  //"Unterteilung";
  cin >> n_x_max >> n_y_max;
  //"exponent";
  cin >> n_exp;
  //"Iterationsschritte";
  cin >> n_max_iter;
  //"Konvergenzradius";
  cin >> r_conv;
  //"Dateiname";
  cin >> filename;
  //"Komplexe Konstante";
  cin >> tmp[0] >> tmp[1];


//ofstream für Ausgabedatei vorbereiten
ofstream dateiout(filename);

//Berechnung delta_x und delta_y
  delta_x = (x_m - x0) / n_x_max;
  delta_y = (y_m - y0) / n_y_max;

 //2 for-Schleifen, die Intervalle durchlaufen
  for (size_t i = 0; i < n_x_max; i++) {
    for (size_t j = 0; j < n_y_max; j++) {
      
      //z0 und c0 für die verschiedenen Teilaufgaben und Startwerte
      switch (nr_iter) {
        case 1:
          z0 = MyComplex(x0 + i * delta_x,
                         y0 + j * delta_y);  // als startwert test
          c0 = MyComplex(tmp[0], tmp[1]);
          break;
        case 2:
          c0 = MyComplex(x0 + i * delta_x,
                         y0 + j * delta_y);
          z0 = MyComplex(tmp[0], tmp[1]);
          break;
        case 3:
          c0 = MyComplex(x0 + i * delta_x,
                         y0 + j * delta_y);
          z0 = MyComplex(tmp[0], tmp[1]);
          break;

        default:
          cout << "error";
          break;
      }

         
      //Variable die Iterationsschritte zählt
      int i_iter = 0;

      //while-Schleife die erst endet, wenn Konvergenzradius oder maximale Iterationen erreicht
      while (z0.norm() < r_conv && i_iter < n_max_iter) {
        z1 = z0;  // Startwert z0 zuweisen
        
        // in for wird Potenz berechnet
        for (size_t p = 1; p < n_exp; p++) {
          z1 = z1 * z0;  
        }
        
        z1 = z1 + c0;  // c0 dazu addieren

        //cout << z1.real() << " " << z1.imag() << " " << i << endl; 
        
        z0 = z1;  // z1 ist nun der neue Wert von z0
        i_iter++;
      }
      
      //Ausgabedatei schreiben
      dateiout << i << " " << j << " "<< i_iter << endl;
      
    }
  }
  return 0;
}
