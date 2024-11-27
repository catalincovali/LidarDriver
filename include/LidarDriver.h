#ifndef LIDARDRIVER_H
#define LIDARDRIVER_H
#include <iostream>
#include <ostream>
#include <vector>

class LidarDriver {
private:



public:
	double get_distance(double angle);
	int get_last();
};

std::ostream& operator<<(std::ostream& os, std::vector<std::vector<double>> v);

#endif
