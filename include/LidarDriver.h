#ifndef LIDARDRIVER_H
#define LIDARDRIVER_H
#include <iostream>
#include <ostream>
#include <vector>

class LidarDriver {
private:


  void clear(int from, int to);
public:

  std::vector<double> get_scan(); 
  void clear_buffer();


};



#endif
