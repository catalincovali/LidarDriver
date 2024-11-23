#ifndef LIDARDRIVER_H
#define LIDARDRIVER_H
#include <iostream>
#include <ostream>
#include <vector>

class LidarDriver {
private:



public:

  std::vector<double> get_scan(); 
  void clear_buffer();
  void clear(int from, int to);

};



#endif
