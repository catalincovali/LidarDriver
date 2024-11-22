#include <iostream>
#include <ostream>
#include "LidarDriver.h"


//constructr()




//new_scan()




//get_scan()
std::vector<double> LidarDriver::get_scan() {
  std::vector<double> d(size, 0.0);                 //size to be defind
  if (first == last)  return std::vector<double> d; //if buffer empty
  std::swap(v[first], d);                           //v and firs to be defind
  return std::vector<double> d;
}

//clear_buffer()
void LidarDriver::clear_buffer() {
  if (first == last)  return;   //buffer already empty
  if (first < last) {
    for (int i=first; i<last; i++)
      std::fill(v[i].begin(), v[i].end(), 0.0);
  }else{
    for (int i=0; i<last; i++)
      std::fill(v[i].begin(), v[i].end(), 0.0);
    for (int i=last; i<size; i++)
      std::fill(v[i].begin(), v[i].end(), 0.0);
  }
}



//get_distance()




//operator<<
