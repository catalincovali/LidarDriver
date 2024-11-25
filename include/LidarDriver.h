#ifndef LIDARDRIVER_H
#define LIDARDRIVER_H
#include <iostream>
#include <ostream>
#include <vector>
#include <stdexception>
class LidarDriver {
public:

//costruttore
LidarDriver();


//set risoluzione angolo
void set_risoluzione_angolo(double r);


//newscan
void new_scan(std::vector<double> ns);


private:
std::vector<std::vector<double>> buffer_;     //creo il buffer di double 

const int buffer_dim_=10;

const int numero_letture_=static_cast<int>(std::round((angolo_max_ / risoluzione_angolo_)); 
//deve essere un numero intero ( const perche così verrà letto in lettura e non compilazione )

double risoluzione_angolo_ ;    // non so se mettere const double risoluzione_angolo_

const int angolo_max_=180;


};

#endif

#endif
