#ifndef LIDARDRIVER_H
#define LIDARDRIVER_H
#include <iostream>
#include <ostream>
#include <vector>
#include <stdexcept>  //for std::out_of_range
#include <cmath>      //for std::round

class LidarDriver {
private:
  std::vector<std::vector<double>> buffer_;
  int first;                    //first = -1 when isEmpty
  int last;                     //last refers to first empty space

  const int BUFFER_DIM_= 4;     //max scansioni
  const double DEF_ANG_= 1.0;   //risoluzione_angolare_ di default
  const int ANGOLO_MAX_ = 180;  //angolo massimo di lettura

  int numero_letture_;          //scan size
  double risoluzione_angolo_;
  bool isEmpty;                 //notify if buffer is empty

  //Function scrivi_buffer()
  void scrivi_buffer(std::vector<double> sb);

public:
  //default constructor()
  LidarDriver();
  //constructor( risoluzione_angolo_ )
  LidarDriver(double a);
  //new_scan()
  void new_scan(std::vector<double> ns);
  //get_scan()
  std::vector<double> get_scan(); 
  //clear_buffer()
  void clear_buffer();
  //get_distance()
  double get_distance(double angle);
  //Function get_last(), ritorna l'ultima scansione inserita
  std::vector<double> get_last(void) {return buffer_.at(last-1);}
};

//overload<<
std::ostream& operator<<(std::ostream& os, LidarDriver& v);

#endif
