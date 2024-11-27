#ifndef LIDARDRIVER_H
#define LIDARDRIVER_H
#include <iostream>
#include <ostream>
#include <vector>

class LidarDriver {
private:
std::vector<std::vector<double>> buffer_;
  int first;
  int last;

  const int BUFFER_DIM_=4;
  const double DEF_ANG_=1.0;
  const int ANGOLO_MAX_ = 180;

  int numero_letture_;
  double risoluzione_angolo_;
  bool isEmpty;


public:

  LidarDriver();
  LidarDriver(double a);

	double get_distance(double angle);
	std::vector<double> get_last(void) {return buffer_.at(last);}
};

std::ostream& operator<<(std::ostream& os, LidarDriver& v);

#endif
