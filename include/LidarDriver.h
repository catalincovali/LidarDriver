#ifndef LIDARDRIVER_H
#define LIDARDRIVER_H
#include <iostream>
#include <ostream>
#include <vector>
#include <cmath>
#include <stdexcept>
class LidarDriver {
public:

//costruttore
LidarDriver();


//set risoluzione angolo
void set_risoluzione_angolo(double r);


//newscan
void new_scan(std::vector<double> ns);

//funzione che userò nel setter
void scrivi_buffer(std::vector<double> sb);


private:
//creo il buffer
std::vector<std::vector<double>> buffer_; 

const int BUFFER_DIM_=10;

/*
numero letture mi indica il numero di letture dopo aver dato un angolo
utilizzo la funzione round per avere un numero intero come dimensione del 
vettore
*/
static constexpr int 
numero_letture_=static_cast<int>(std::round((angolo_max_ 
/ risoluzione_angolo_)); 
//deve essere un numero intero ( const perche così verrà letto in lettura e non compilazione )

//risoluzione angolo che verrà inizializzata successivamente dalla 
funzione setter
static constexpr double risoluzione_angolo_ ;

const int angolo_max_=180;


};

#endif

#endif
