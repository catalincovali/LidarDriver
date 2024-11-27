
#include "LidarDriver.h"



//construct()
//costruttore con angolo inserito dal main
LidarDriver::LidarDriver(double a)
    :risoluzione_angolo_{a},
      numero_letture_(static_cast<int>(std::round(ANGOLO_MAX_ / 
risoluzione_angolo_))),
      buffer_(BUFFER_DIM_, std::vector<double>(numero_letture_)), // 
Inizializza il buffer
      first(-1), last(0) 
      {
      isEmpty=true;
      if(a<0 || a>1)
      {
      throw std::out_of_range(" la risoluzione dell'angolo non è valida");
      }
      
      numero_letture_ = static_cast<int>(std::round(ANGOLO_MAX_ / 
risoluzione_angolo_))+1;
      
      }



//costruttore di default
LidarDriver::LidarDriver()
    : risoluzione_angolo_(DEF_ANG_),  // Imposta un valore predefinito
      numero_letture_(static_cast<int>(std::round(ANGOLO_MAX_ / 
risoluzione_angolo_))),
      buffer_(BUFFER_DIM_, std::vector<double>(numero_letture_)), // 
Inizializza il buffer
      first(-1), last(0) 
      {
       numero_letture_ = static_cast<int>(std::round(ANGOLO_MAX_ / 
risoluzione_angolo_))+1;
      }




/*scrivo una funzione che mi riempia il buffer nei casi in cui:
1) il vettore inserito abbia l'esatta dimensione del buffer
2) il vettore abbia una dimensione minore e quindi lo riempia con zeri 
3) il vettore ha più valori del buffer e quindi prende solo i primi valori
   che riempiono il buffre  tagliando il restante
*/
void LidarDriver:: scrivi_buffer(std::vector<double> sb){
 size_t size = sb.size();

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
    
  //******************************************se il buffer è vuoto o last 
coincide con first
   if(isEmpty || last==first)
   {
      scrivi_buffer(ns);
      last++;
      first++;
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




//clear_buffer()




//get_distance()




//operator<<

