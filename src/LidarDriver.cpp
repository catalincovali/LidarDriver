#include <iostream>
#include <ostream>
#include <stdexcept> //for std::out_of_range
#include <vector>
#include "LidarDriver.h"


//constructor()




//constructor(angRes)




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
