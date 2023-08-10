#include <iostream>
using namespace std;

int main() {
  int bienes = 0;
  
  cout << "Ingrese la cantidad de bienes que adquirio." << endl;
  cin >> bienes;

  if (bienes >= 4) {
    cout << "Precio total a pagar: " << (50 * bienes) - 20 << "$" << endl;
  } else {
    cout << "Precio total a pagar: " << 50 * bienes << "$" << endl;
  }

  return 0;
}