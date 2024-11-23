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
  if (first == DIM_BUFFER - 1)  first = 0;          //DIM_BUFFER to be defind
  else  first++;
  return std::vector<double> d;
}

//clear_buffer()
void LidarDriver::clear_buffer() {
  if (first == last)  return;   //buffer already empty
  if (first < last) {
    LidarDriver::clear(first, last);
  }else{
    LidarDriver::clear(0, last);
    LidarDriver::clear(first, size);              //szie to be difend
  }
  first = last;   //set empty buffe state
}

void LidarDriver::clear(int from, int to) {
  for(int i = from, i<to, i++)
      std::fill(v[i].begin(), v[i].end(), 0.0);
}



//get_distance()




//operator<<
