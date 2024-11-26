#ifndef LIDARDRIVER_H
#define LIDARDRIVER_H
#include <iostream>
#include <ostream>
#include <stdexcept> //for std::out_of_range
#include <vector>

class LidarDriver {
private:

  //Helper Function clear()
  void clear(int from, int to);

public:





  //get_scan()
  std::vector<double> get_scan(); 
  //clear_buffer()
  void clear_buffer();


};



#endif
