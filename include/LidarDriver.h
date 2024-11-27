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

//costruttore con angolo
LidarDriver(double a);


//new_scan gestirà le parti del buffer dove scrivere o sovrascrivere il

void new_scan(std::vector<double> ns);

//funzione gestirà il vettore da inserire nel new_scan
void scrivi_buffer(std::vector<double> sb);


private:
int first;//mi indica il primo posto del buffer libero per un nuovo scan
int last;//mi indica lo scan più vecchio di tutti
std::vector<std::vector<double>> buffer_;//creo il buffer di double

const int BUFFER_DIM_=4;

int numero_letture_;
double risoluzione_angolo_;
const double DEF_ANG_=1.0;

const int ANGOLO_MAX_ = 180;
};
#endif
