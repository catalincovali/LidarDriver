#include <iostream>
#include <ostream>
#include <stdexcept> //for std::out_of_range
#include <vector>
#include "LidarDriver.h"


//constructor()
LidarDriver::LidarDriver()
  : angRes{DEF_angRes},
    v (DIM_BUFFER, std::vector<double>(static_cast<int>(ANG_MAX / angRes) + 1, 0.0 ))
{
  scanSize = static_cast<int>(ANG_MAX/angRes)+1;
  first = 0;                
  last = 0;                 
}

//constructor(angRes)
LidarDriver::LidarDriver(double arg) {
  if (arg < 0.1 || arg > 1.0)
    throw std::out_of_range("out of range");

  first = 0;                
  last = 0;                 
  angRes = arg;
  scanSize = static_cast<int>(ANG_MAX/angRes)+1;
  
  //initialize buffer
  v = std::vector<std::vector<double>>(DIM_BUFFER, std::vector<double>(scanSize, 0.0));
}

//new_scan()




//get_scan()
std::vector<double> LidarDriver::get_scan() {
  std::vector<double> d(scanSize, 0.0);
  if (first == last)  return d; 
  std::swap(v[first], d);

  if (first == DIM_BUFFER - 1)  first = 0;
  else  first++;

  return d;
}

//clear_buffer()
void LidarDriver::clear_buffer() {
  if (first == last)  return;   //buffer already empty
  if (first < last) {
    LidarDriver::clear(first, last);
  }else{
    LidarDriver::clear(0, last);
    LidarDriver::clear(first, scanSize);
  }
  first = last;   //set empty buffer state
}

void LidarDriver::clear(int from, int to) {
  for(int i = from; i<to; i++)
      std::fill(v[i].begin(), v[i].end(), 0.0);
}



//get_distance()




//operator<<
