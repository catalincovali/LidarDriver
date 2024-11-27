#include <iostream>
#include <ostream>
#include <vector>
#include <random>

std::vector<double>& generateNumbers (int size);
void printGetScan( std::vector<double> v );

int main() {
  
  LidarDriver driver1();
  LidarDriver driver2(0.2);

  int size = 100;
  std::vector<double> n1 = generateNumbers(size, 1);
  std::vector<double> n2 = generateNumbers(size*2, 2);
  std::vector<double> n3 = generateNumbers(size*2, 3);
  std::vector<double> n4 = generateNumbers(size, 4);
  std::vector<double> n5 = generateNumbers(size, 5);
  std::vector<double> n6 = generateNumbers(size, 6);

  driver1.new_scan(n1);
  driver1.new_scan(n2);
  std::cout << "lettura: " << driver1 << "\n";
  printGetScan( driver1.get_scan() );
  driver1.clear_buffer();

  driver1.new_scan(n1);
  driver1.new_scan(n2);
  driver1.new_scan(n3);
  printGetScan( driver1.get_scan() );
   








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
  retunr v;
}
