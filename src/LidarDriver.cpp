
#include "LidarDriver.h"



//construct()
LidarDriver::LidarDriver() :buffer_(BUFFER_DIM_, 
std::vector<double>(numero_letture_))
{  
first=0;
last=0;
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




/*scrivo una funzione che mi riempia il buffer nei casi in cui:
1) il vettore inserito abbia l'esatta dimensione del buffer
2) il vettore abbia una dimensione minore e quindi lo riempia con zeri 
3) il vettore ha più valori del buffer e quindi prende solo i primi valori
   che riempiono il buffre  tagliando il restante
*/
void LidarDriver:: scrivi_buffer(std::vector<double> sb){
 size_t size = sb.size();
 if (size == numero_letture_){
         for (int j=0; j<size;j++){
             buffer_[last][j]=scan[j];
         }
      }
 else if (size< numero_letture_){
         for (int j=0; j<size;j++){
             buffer_[last][j]=scan[j];
         }//copio i valori del vettore nel buffer 
         for (int i=size; i<numero_letture_;i++){
             buffer_[last][i]=0;
         }//secondo for che mi riempie il buffer di zeri per arrivare a riempire tutte le letture
      }// minore riempio con 0
      
 else {
        for (int j=0; j<numero_letture_;j++){
             buffer_[last][j]=scan[j];
         }
      }
      //se size ha una dimensione maggiore taglio i valori dopo 
      
}


//funzione new scan
void LidarDriver::new_scan ( std::vector<double> ns) {
   
   if(last != 10 && last >=first){
     scrivi_buffer(ns);
     last ++;
    }
    
    else if ( (last=10 || last<first) && first !=10){
    scrivi_buffer(ns);
    last=first;
    first++;
    }
    
    else // quando first raggiunge l'ultimo scan del buffer 
    { scrivi_buffer(ns);
      first=0;
      last++;
    }
 }
   





//get_scan()




//clear_buffer()




//get_distance()




//operator<<

