#ifndef LIDARDRIVER_H
#define LIDARDRIVER_H
#include <iostream>
#include <ostream>
#include <stdexcept> //for std::out_of_range
#include <vector>

class LidarDriver {
private:
  std::vector <std::vector<double> > v; //buffer 

  const int DIM_BUFFER = 10;
  const double ANG_MAX= 180;
  const double DEF_angRes = 0.5;
  
  int first;            //first scan
  int last;             //last scan
  double angRes;        //defined by user in main
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
