#include <iostream> 
using namespace std;

int main() {
    int numero; //Variable para alamacenar el numero ingresado

    //Solicitar al usuario que ingrese un numero
    cout << "Ingresar el numero: ";
    cin >> numero;

    //Verificar si el numero es par o impar
    if (numero % 2 == 0) {
        cout << "El numer numero es par" << endl;
    } else {
        cout << "El numer numero es impar" << endl;
    }
  
  return 0;
}