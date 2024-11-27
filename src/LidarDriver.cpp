#include <iostream>
#include <ostream>
#include <vector>
#include "LidarDriver.h"


//constructor()
LidarDriver::LidarDriver()
{
  risoluzione_angolo_ = DEF_ANG_;  
  numero_letture_ = static_cast<int>(std::round(ANGOLO_MAX_ / risoluzione_angolo_));
  buffer_ = std::vector<std::vector<double>>(BUFFER_DIM_, std::vector<double>(numero_letture_));
  first = -1;
  last = 0; 
  numero_letture_ = static_cast<int>(std::round(ANGOLO_MAX_ / risoluzione_angolo_))+1;
}



//constructor(angRes)
LidarDriver::LidarDriver(double a) : risoluzione_angolo_{a}
{
  isEmpty=true;
  if(a<0 || a>1)  
    throw std::out_of_range(" la risoluzione dell'angolo non è valida");

  numero_letture_ = static_cast<int>(std::round(ANGOLO_MAX_ / risoluzione_angolo_));
  buffer_ = std::vector<std::vector<double>>(BUFFER_DIM_, std::vector<double>(numero_letture_));
  first = -1;
  last = 0; 
      
  numero_letture_ = static_cast<int>(std::round(ANGOLO_MAX_/risoluzione_angolo_))+1;
}


//new_scan()
/*scrivo una funzione che mi riempia il buffer nei casi in cui:
1) il vettore inserito abbia l'esatta dimensione del buffer
2) il vettore abbia una dimensione minore e quindi lo riempia con zeri 
3) il vettore ha più valori del buffer e quindi prende solo i primi valori
   che riempiono il buffre  tagliando il restante
*/
void LidarDriver:: scrivi_buffer(std::vector<double> sb){
 int size = sb.size();

 if (size == numero_letture_)                  //1)
      {
         for (int j=0; j<size;j++){
             buffer_[last][j]=sb[j];
         }
      }

 else if (size< numero_letture_)               //2)
      {
         for (int j=0; j<size;j++){
             buffer_[last][j]=sb[j];
         }//copio i valori del vettore nel buffer 
         for (int i=size; i<numero_letture_;i++){
             buffer_[last][i]=0;
         }//inizializzo i valori restanti a 0
      }
      
 else                                          //3)
      {
        for (int j=0; j<numero_letture_;j++){
             buffer_[last][j]=sb[j];
         }
      } 
      
}


//funzione new scan
void LidarDriver::new_scan ( std::vector<double> ns) {
    
  //******************************************se il buffer è vuoto o last coincide con first
   if(isEmpty || last==first)
   {
      scrivi_buffer(ns);
      last++;
      first++;
      isEmpty=false;
      if(last==BUFFER_DIM_){ 
      last=0; 
      first=0;
      }
      
   }
  //******************************************quando il buffer non è vuoto   
   else
   {
       scrivi_buffer(ns);
       last++;
       if(last==BUFFER_DIM_){
         last=0;
       }
   }
    
 }



//get_scan()
std::vector<double> LidarDriver::get_scan() {
  if (isEmpty)  return std::vector<double> (numero_letture_, 0.0);
  
  if (first == BUFFER_DIM_ - 1) {
    first = 0;
    return buffer_[BUFFER_DIM_ - 1];
  }
  
  first++;

  if (first == last) { 
    isEmpty = true;
    first = -1;
    last = 0;
  }

  return buffer_[first - 1];
}

//clear_buffer()
void LidarDriver::clear_buffer() {
  if (isEmpty)  return;   
  isEmpty = true;
  first = -1;
  last = 0;
}

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
