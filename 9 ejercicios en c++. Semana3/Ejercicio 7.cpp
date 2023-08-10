#include <iostream>
using namespace std;

int main() {
    int numero;
    string mes;

    // Listado de números de acuerdo con el mes
    cout << "Listado de números de acuerdo con el mes:" << endl;
    cout << "1 = enero" << endl;
    cout << "2 = febrero" << endl;
    cout << "3 = marzo" << endl;
    cout << "4 = abril" << endl;
    cout << "5 = mayo" << endl;
    cout << "6 = junio" << endl;
    cout << "7 = julio" << endl;
    cout << "8 = agosto" << endl;
    cout << "9 = septiembre" << endl;
    cout << "10 = octubre" << endl;
    cout << "11 = noviembre" << endl;
    cout << "12 = diciembre" << endl;

    // Ingresar un número de referencia para el mes
    cout << "Ingrese un número: ";
    cin >> numero;

    // Verificar si el número ingresado está dentro del rango válido (1 a 12)
    if (numero > 0 && numero < 13) {
        // Asignar el mes correspondiente según el número ingresado
        switch (numero) {
            case 1:
                mes = "enero";
                break;
            case 2:
                mes = "febrero";
                break;
            case 3:
                mes = "marzo";
                break;
            case 4:
                mes = "abril";
                break;
            case 5:
                mes = "mayo";
                break;
            case 6:
                mes = "junio";
                break;
            case 7:
                mes = "julio";
                break;
            case 8:
                mes = "agosto";
                break;
            case 9:
                mes = "septiembre";
                break;
            case 10:
                mes = "octubre";
                break;
            case 11:
                mes = "noviembre";
                break;
            case 12:
                mes = "diciembre";
                break;
        }
    } else {
        // Si el número ingresado está fuera del rango válido, mostrar un mensaje de error
        cout << "Ingresaste un número fuera del rango válido (1 a 12)." << endl;
        return 1; // Terminar el programa con código de error 1
    }

    // Mostrar el número y el mes correspondiente
    cout << "El número " << numero << " corresponde al mes de " << mes << "." << endl;
    return 0;
}
