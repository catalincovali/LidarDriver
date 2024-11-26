#include <iostream>
#include "LidarDriver.h"
int main() {
  //creo l'oggetto LidarDriver con nome lidar
  LidarDriver lidar;

  /*setto la risoluzione dell'angolo a 0.5,
    questo mi calcolerà in automatico anche il numero di letture*/
  lidar.set_risoluzione_angolo(0.5);

  //creo il vettore che poi inserirò come new_scan
  std::vector<double> v={1.1,1.2,1.3,1.4,1.5,1.6,1.7,1.8};
  
  //inserisco il new_scan
  lidar.new_scan(v);
  
  return 0;
}
