#include <iostream>
#include <ostream>
#include <vector>
#include "LidarDriver.h"


//constructor()
LidarDriver::LidarDriver()
    : risoluzione_angolo_(DEF_ANG_),  // Imposta un valore predefinito
      numero_letture_(static_cast<int>(std::round(ANGOLO_MAX_ / risoluzione_angolo_))),
      buffer_(BUFFER_DIM_, std::vector<double>(numero_letture_)), first(-1), last(0) 
{
  numero_letture_ = static_cast<int>(std::round(ANGOLO_MAX_ / risoluzione_angolo_))+1;
}



//constructor(angRes)
LidarDriver::LidarDriver(double a)
    :risoluzione_angolo_{a},
      numero_letture_(static_cast<int>(std::round(ANGOLO_MAX_ / risoluzione_angolo_))),
      buffer_(BUFFER_DIM_, std::vector<double>(numero_letture_)),first(-1), last(0) 
{
  isEmpty=true;
  if(a<0 || a>1)  
    throw std::out_of_range(" la risoluzione dell'angolo non è valida");

      
  numero_letture_ = static_cast<int>(std::round(ANGOLO_MAX_/risoluzione_angolo_))+1;
}


//new_scan()




//get_scan()
std::vector<double> LidarDriver::get_scan() {
  if (isEmpty)  return std::vector<double> (numero_letture_, 0.0);
  
  if (first == BUFFER_DIM_ - 1) {
    first = 0;
    return buffer_[BUFFER_DIM_ - 1];
  }
  
  first++;

  if (first == last) { 
    isEmpty = true;
    first = -1;
    last = 0;
  }

  return buffer_[first - 1];
}

//clear_buffer()
void LidarDriver::clear_buffer() {
  if (isEmpty)  return;   
  isEmpty = true;
  first = -1;
  last = 0;
}

//get_distance()




//operator<<
