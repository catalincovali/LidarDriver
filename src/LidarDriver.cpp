#include <iostream>
#include <ostream>
#include <cmath>	//per std::round
#include <vector>
#include <stdexcept>	//per std::out_of_range
#include "LidarDriver.h"



//constructr()




//new_scan()




//get_scan()




//clear_buffer()




//get_distance()
double LidarDriver::get_distance(double angle){
		
	if(angle<0 || angle>180)
		throw std::out_of_range("l'angolo deve essere compreso tra 0 e 180");
	
	double tempIndex = angle/risoluzione_angolare;
	int index = static_cast<int>( std::round(tempIndex) );
	double lettura = v.at(last-1).at(index);
	
	return lettura;
}



//operator<<
std::ostream& operator<<(std::ostream& os, std::vector<std::vector<double>>& v){
	os << "[";
	for(int i=0; i < v.size(); i++){
		os << v.at(v.get_last()-1).at(i);
		if(i != v.size()-1) os << ", ";		
	}
	os << "]";
	return os;
}


//get_last()
int LidarDriver::get_last(){
	return last;
}

