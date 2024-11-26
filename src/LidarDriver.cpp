
#include "LidarDriver.h"



//construct()
/*creo un buffer con dimensione predefinita e con risoluzione_angolo_ con valore 
di default che verra poi cambiata dal setter della risoluzione angolo, cambiando
automaticamente anche il buffer */
LidarDriver::LidarDriver() : risoluzione_angolo_(1.0), numero_letture_(static_cast<int>(std::round(angolo_max_ / 
risoluzione_angolo_))), buffer_(BUFFER_DIM_, std::vector<double>(numero_letture_)), first(0), last(0) {}//inizializzo anche fist e last a 0



/*controllo che la grandezza dell'angolo inserito sia adeguata
in caso non lo sia lancio l'eccezione out_of_range*/ 
void LidarDriver:: set_risoluzione_angolo(double r){
      if ( r>0 && r<1) {
        risoluzione_angolo_ = r;
        
        //calcolo anche il numero di letture
        numero_letture_ = static_cast<int>(std::round(angolo_max_ / 
risoluzione_angolo_));
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
   
   if(last != 10 && last >=first)   //primo if che mi serve per scrivere 
                                    //i primi 10 scan
    {
     scrivi_buffer(ns);  //utilizzo la funzione scrivi buffer per inserire 
                        //i valori del vettore ns nel buffer in posizione 
     last ++;           //incremento last
    }
    
    else if ( (last=10 || last<first) && first !=10)  //secondo if che mi gestisce quando 
                                             //last arriva a 10 e deve sovrascrivere first
    {
     scrivi_buffer(ns);
     last=first;
     first++;
    }
    
    else    // quando first raggiunge la posizione 10 e deve ritornare
            // alla posizione 0 così last diventa nuovamente la posizione 10
    { 
      scrivi_buffer(ns);
      first=0;
      last++;
    }
 }
   





//get_scan()




//clear_buffer()




//get_distance()




//operator<<

