#include <iostream>
#include <ostream>
#include <vector>
#include "LidarDriver.h"


//constructor()
LidarDriver::LidarDriver() {
    risoluzione_angolo_ = DEF_ANG_;  
    numero_letture_ = static_cast<int>(std::round(ANGOLO_MAX_ / risoluzione_angolo_));
    if (numero_letture_ <= 0) {
        throw std::out_of_range("Numero di letture calcolato non valido.");
    }
   
    buffer_ = std::vector<std::vector<double>>(BUFFER_DIM_, std::vector<double>(numero_letture_));
    first = -1;
    last = 0;
    isEmpty = true;
}




//constructor(angRes)
LidarDriver::LidarDriver(double a) : risoluzione_angolo_{a} {
    if (a <= 0 || a > ANGOLO_MAX_) {
        throw std::out_of_range("La risoluzione dell'angolo non è valida");
    }

    // Calcola il numero di letture
    numero_letture_ = static_cast<int>(std::round(ANGOLO_MAX_ / risoluzione_angolo_));
    if (numero_letture_ <= 0) {
        throw std::out_of_range("Numero di letture calcolato non valido.");
    }

    buffer_ = std::vector<std::vector<double>>(BUFFER_DIM_, std::vector<double>(numero_letture_));
    first = -1;
    last = 0;
    isEmpty = true;
}



//new_scan()
/*scrivo una funzione che mi riempia il buffer nei casi in cui:
1) il vettore inserito abbia l'esatta dimensione del buffer
2) il vettore abbia una dimensione minore e quindi lo riempia con zeri
3) il vettore ha più valori del buffer e quindi prende solo i primi valori
   che riempiono il buffre  tagliando il restante
*/
void LidarDriver::scrivi_buffer(std::vector<double> sb) {
    int size = sb.size();
   
    if (size > numero_letture_) {
        sb.resize(numero_letture_); // Ridimensiona sb se troppo grande
    }
   
    if (size < numero_letture_) {
        sb.resize(numero_letture_, 0.0); // Riempie con zeri se troppo piccolo
    }
   
    // Copia i valori nel buffer
    for (int j = 0; j < size; j++) {
        buffer_[last][j] = sb[j];
    }
}



//funzione new scan
void LidarDriver::new_scan(std::vector<double> ns) {
    if (isEmpty || last == first) {
        scrivi_buffer(ns);
        last = (last + 1) % BUFFER_DIM_;  // Usa modulo per evitare overflow
        first = (first + 1) % BUFFER_DIM_; // Anche first deve essere incrementato correttamente
        isEmpty = false;
    } else {
        scrivi_buffer(ns);
        last = (last + 1) % BUFFER_DIM_;
    }
}




//get_scan()
std::vector<double> LidarDriver::get_scan() {
    if (isEmpty) {
        return std::vector<double>(numero_letture_, 0.0);
    }

    // Se first è all'inizio del buffer, iniziamo a restituire l'elemento corretto
    if (first == BUFFER_DIM_ - 1) {
        first = 0;
        return buffer_[BUFFER_DIM_ - 1];
    }

    // Altrimenti, incrementiamo first
    first++;

    if (first == last) {
        isEmpty = true;
        first = -1;
        last = 0;
    }

    return buffer_[first - 1]; // Restituiamo l'elemento appena precedente first
}



//clear_buffer()
void LidarDriver::clear_buffer() {
  if (isEmpty)  return;  
  isEmpty = true;
  first = -1;
  last = 0;
}



//get_distance()
double LidarDriver::get_distance(double angle) {
    if (angle < 0 || angle > 180) {
        throw std::out_of_range("l'angolo deve essere compreso tra 0 e 180");
    }

    // Verifica che `last` sia valido
    if (last <= 0) {
        throw std::out_of_range("Buffer is empty, cannot get distance.");
    }

    double tempIndex = angle / risoluzione_angolo_;
    int index = static_cast<int>(std::round(tempIndex));

    if (index < 0 || index >= numero_letture_) {
        throw std::out_of_range("Angle out of bounds for the current scan.");
    }

    return buffer_.at(last - 1).at(index);
}




std::vector<double> LidarDriver::get_last(void) {
    if (isEmpty) {
        throw std::out_of_range("Buffer is empty, cannot retrieve last element.");
    }
    return buffer_.at(last - 1); // Assicurati che `last` > 0
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
