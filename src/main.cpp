#include <iostream>
#include <ostream>
#include <vector>
#include "LidarDriver.h"

std::vector<double> generateNumbers (int size, int value);
void printGetScan( std::vector<double> v );

int main() {

  LidarDriver driver1;
  LidarDriver driver2(0.8);

  int size = 100;
  std::vector<double> n1 = generateNumbers(size, 1);    //genera un vettore di valori = 1.0
  std::vector<double> n2 = generateNumbers(size*2, 2);
  std::vector<double> n3 = generateNumbers(size*2, 3);
  std::vector<double> n4 = generateNumbers(size, 4);
  std::vector<double> n5 = generateNumbers(size, 5);
  std::vector<double> n6 = generateNumbers(size, 6);

//------------------------------------------------------------
//Test Driver1
  std::cout << "\n\n\n";
  std::cout << "DRIVER1 risoluzione_angolare_ = 1.0\n\n";


  driver1.new_scan(n1); std::cout << "scansione n1\n";
  driver1.new_scan(n2); std::cout << "scansione n2\n";
  std::cout << "lettura ultima scansione:\n" << driver1 << "\n\n";

  driver1.new_scan({1.0, 2.0, 3.0, 4.0, 5.0});
  std::cout << "lettura ultima scansione:\n" << driver1 << "\n\n";
  std::cout << "Lettura angolo (2.1): " << driver1.get_distance(2.1) << "\n\n"; //output -> 3.0 

  printGetScan( driver1.get_scan() );
  driver1.clear_buffer();

  driver1.new_scan(n1); std::cout << "scansione n1\n";
  driver1.new_scan(n2); std::cout << "scansione n2\n";
  driver1.new_scan(n3); std::cout << "scansione n3\n";
  printGetScan( driver1.get_scan() );
   
  driver1.new_scan(n4); std::cout << "scansione n4\n";
  driver1.new_scan(n5); std::cout << "scansione n5\n";
  driver1.new_scan(n6); std::cout << "scansione n6\n";
  printGetScan( driver1.get_scan() );

  std::cout << "lettura ultima scansione:\n" << driver1 << "\n\n";


//------------------------------------------------------------
//Test Driver2

  std::cout << "\n\n\n";
  std::cout << "DRIVER2 risoluzione_angolare_ = 0.8\n\n";


  driver2.new_scan(n1); std::cout << "scansione n1\n";
  driver2.new_scan(n2); std::cout << "scansione n2\n";
  std::cout << "lettura ultima scansione:\n" << driver2 << "\n\n";

  driver2.new_scan({1.0, 2.0, 3.0, 4.0, 5.0});
  std::cout << "lettura ultima scansione:\n" << driver2 << "\n\n";
  std::cout << "Lettura angolo (2.1): " << driver2.get_distance(2.1) << "\n\n"; 

  printGetScan( driver2.get_scan() );
  driver2.clear_buffer();

  driver2.new_scan(n1); std::cout << "scansione n1\n";
  driver2.new_scan(n2); std::cout << "scansione n2\n";
  driver2.new_scan(n3); std::cout << "scansione n3\n";
  printGetScan( driver2.get_scan() );
   
  driver2.new_scan(n4); std::cout << "scansione n4\n";
  driver2.new_scan(n5); std::cout << "scansione n5\n";
  driver2.new_scan(n6); std::cout << "scansione n6\n";
  printGetScan( driver2.get_scan() );

  std::cout << "lettura ultima scansione:\n" << driver2 << "\n\n";


  return 0;
}

void printGetScan( std::vector<double> v ){
  std::cout << "Scansione eliminata:\n";
  for (int i=0; i<v.size(); i++)
    std::cout << v.at(i) << ", ";
  std::cout << "\n\n";
} 

std::vector<double> generateNumbers (int size, int value) {
  std::vector<double> v(size);
  for (int i=0; i<size; i++)
    v.at(i)=value;
  return v;
}
