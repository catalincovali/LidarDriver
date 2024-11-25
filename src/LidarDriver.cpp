
#include "LidarDriver.h"



//construct()
LidarDriver::LidarDriver() :buffer_(buffer_dim_, std::vector<double>(numero_letture_))
{  
}     // do la dimensione al buffer



//controllo che la grandezza dell'angolo inserito sia adeguata con un set 
void LidarDriver:: set_risoluzione_angolo(double r){
      if ( r>0 && r<1) {
        risoluzione_angolo_ = r;
      }
      else {
      throw std::out_of_range(" la risoluzione dell'angolo non è valida")
      }
}




//new_scan()




//get_scan()




//clear_buffer()




//get_distance()




//operator<<

