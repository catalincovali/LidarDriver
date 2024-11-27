#include <iostream>
#include <ostream>
#include <cmath>	//per std::round
#include <vector>
#include <stdexcept>	//per std::out_of_range
#include "LidarDriver.h"



//constructr()

LidarDriver::LidarDriver()
    : risoluzione_angolo_(DEF_ANG_),  // Imposta un valore predefinito
      numero_letture_(static_cast<int>(std::round(ANGOLO_MAX_ / risoluzione_angolo_))),
      buffer_(BUFFER_DIM_, std::vector<double>(numero_letture_)), first(-1), last(0) 
{
  numero_letture_ = static_cast<int>(std::round(ANGOLO_MAX_ / risoluzione_angolo_))+1;
}




//constructor(angRes)
LidarDriver::LidarDriver(double a)
    :risoluzione_angolo_{a},
      numero_letture_(static_cast<int>(std::round(ANGOLO_MAX_ / risoluzione_angolo_))),
      buffer_(BUFFER_DIM_, std::vector<double>(numero_letture_)),first(-1), last(0) 
{
  isEmpty=true;
  if(a<0 || a>1)  
    throw std::out_of_range(" la risoluzione dell'angolo non è valida");

      
  numero_letture_ = static_cast<int>(std::round(ANGOLO_MAX_/risoluzione_angolo_))+1;
}
      
      
      
//new_scan()




//get_scan()




//clear_buffer()




//get_distance()
double LidarDriver::get_distance(double angle){
		
	if(angle<0 || angle>180)
		throw std::out_of_range("l'angolo deve essere compreso tra 0 e 180");
	
	double tempIndex = angle/risoluzione_angolo_;
	int index = static_cast<int>( std::round(tempIndex) );
	double lettura = buffer_.at(last-1).at(index);
	
	return lettura;
}



//operator<<
std::ostream& operator<<(std::ostream& os, LidarDriver& v){
	os << "[";
	std::vector<double> myVec = v.get_last(); 
	for(int i=0; i < myVec.size(); i++){
		os << myVec.at(i);
		if(i != myVec.size()-1) os << ", ";		
	}
	os << "]";
	return os;
}


