#ifndef LIDARDRIVER_H
#define LIDARDRIVER_H
#include <iostream>
#include <ostream>
#include <stdexcept> //for std::out_of_range
#include <vector>

class LidarDriver {
private:
  std::vector <std::vector<double> > v; 

  const int DIM_BUFFER = 10;
  const double ANG_MAX= 180;
  const double DEF_angRes = 0.5;      //dafult value of angRes
  
  int first = 0;                //first scan
  int last = 1;                 //last empty space (last scan = last-1)
  double angRes;                //defined by user
  int scanSize;

  //Helper Function clear()
  void clear(int from, int to);
public:
  //constructor()
  LidarDriver(); 
  //constructor(angRes)
  LidarDriver(double arg);
  

  //get_scan()
  std::vector<double> get_scan(); 
  //clear_buffer()
  void clear_buffer();


};



#endif
