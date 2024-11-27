#ifndef LIDARDRIVER_H
#define LIDARDRIVER_H
#include <iostream>
#include <ostream>
#include <stdexcept> //for std::out_of_range
#include <vector>

class LidarDriver {
private:
  std::vector<std::vector<double>> buffer_;
  int first;
  int last;

  const int BUFFER_DIM_=4;
  const double DEF_ANG_=1.0;
  const int ANGOLO_MAX_ = 10;

  int numero_letture_;
  double risoluzione_angolo_;
  bool isEmpty;

public:
  LidarDriver();
  LidarDriver(double a);
  
  void new_scan(std::vector<double> ns);
  void scrivi_buffer(std::vector<double> sb);

  //get_scan()
  std::vector<double> get_scan(); 
  //clear_buffer()
  void clear_buffer();

  double get_distance(double angle);
	std::vector<double> get_last(void) {return buffer_.at(last-1);}

};

std::ostream& operator<<(std::ostream& os, LidarDriver& v);



#endif
