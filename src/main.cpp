#include <iostream>
#include <ostream>
#include <vector>
#include <random>
#include "LidarDriver.h"
std::vector<double> generateNumbers (int size, int value);
void printGetScan( std::vector<double> v );

int main() {

  LidarDriver driver1;
  LidarDriver driver2(0.2);

  int size = 100;
  std::vector<double> n1 = generateNumbers(size, 1);
  std::vector<double> n2 = generateNumbers(size*2, 2);
  std::vector<double> n3 = generateNumbers(size*2, 3);
  std::vector<double> n4 = generateNumbers(size, 4);
  std::vector<double> n5 = generateNumbers(size, 5);
  std::vector<double> n6 = generateNumbers(size, 6);

//------------------------------------------------------------
//Test Driver1

  driver1.new_scan(n1);
  driver1.new_scan(n2);
  std::cout << "lettura: " << driver1 << "\n";

  driver1.new_scan({1.0, 2.0, 3.0, 4.0, 5.0});
  std::cout << "Lettura angolo = 2.1 : " << driver1.get_distace(2.1) << "\n"; //output -> 3.0 

  printGetScan( driver1.get_scan() );
  driver1.clear_buffer();

  driver1.new_scan(n1);
  driver1.new_scan(n2);
  driver1.new_scan(n3);
  printGetScan( driver1.get_scan() );
   
  driver1.new_scan(n4);
  driver1.new_scan(n5);
  driver1.new_scan(n6);
  printGetScan( driver1.get_scan() );

  std::cout << "lettura: " << driver1 << "\n";

//------------------------------------------------------------
//Test Driver2

  driver2.new_scan(n1);
  driver2.new_scan(n2);
  std::cout << "lettura: " << driver2 << "\n";

  driver2.new_scan({1.0, 2.0, 3.0, 4.0, 5.0});
  std::cout << "Lettura angolo = 2.1 : " << driver1.get_distace(2.1) << "\n"; //output -> 3.0 

  printGetScan( driver1.get_scan() );
  driver2.clear_buffer();

  driver2.new_scan(n1);
  driver2.new_scan(n2);
  driver2.new_scan(n3);
  printGetScan( driver2.get_scan() );
   
  driver2.new_scan(n4);
  driver2.new_scan(n5);
  driver2.new_scan(n6);
  printGetScan( driver2.get_scan() );

  std::cout << "lettura: " << driver2 << "\n";


  return 0;
}

void printGetScan( std::vector<double> v ){
  std::cout << "Deleted Scan: ";
  for (int i=0; i<v.size(); i++)
    std::cout << v.at(i) << ", ";
  std::cout << "\n";
} 

std::vector<double> generateNumbers (int size, int value) {
  std::vector<double> v(size);
  for (int i=0; i<size; i++)
    v.push_back(value);
  return v;
}
