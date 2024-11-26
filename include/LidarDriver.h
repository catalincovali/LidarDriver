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


/*  funzione di set della risoluzione angolo che controlla che l'angolo
inserito sia corretto in alternativa lancia l'eccezione out_of_range   */
void set_risoluzione_angolo(double r);


//new_scan gestirà le parti del buffer dove scrivere o sovrascrivere il
nuovo vettore
void new_scan(std::vector<double> ns);

//funzione gestirà il vettore da inserire nel new_scan
void scrivi_buffer(std::vector<double> sb);


private:
//creo il buffer
std::vector<std::vector<double>> buffer_;

const int BUFFER_DIM_=10;

/*
numero letture viene inizializzato nella funzione setter dell'angolo, mi
indica il numero di letture calcolato in base all'angolo inserito nel 
setter
*/
int numero_letture_; 

//risoluzione angolo che verrà inizializzata successivamente dalla 
funzione setter
double risoluzione_angolo_;

const int angolo_max_=180;


};
#endif
