#include <iostream>
#include <ostream>
#include <vector>
#include "LidarDriver.h"


//constructor()




//constructor(angRes)




//new_scan()




//get_scan()
std::vector<double> LidarDriver::get_scan() {
  if (isEmpty)  return std::vector<double> d(scanSize, 0.0);
  
  if (first == DIM_BUFFER - 1) {
    first = 0;
    return v[DIM_BUFFER - 1];
  }
  
  first++;

  if (first == last) { 
    isEmpty = true;
    first = -1;
    last = 0;
  }

  return v[first - 1];
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
