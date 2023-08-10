#include <iostream>
using namespace std;

int main() {
    double saldo = 1000.0;
    int opcion;
    
    cout << "Bienvenido al Banco Inteligente" << endl;
    
    while (true) {
        cout << "Opciones:" << endl;
        cout << "1 = Mostrar saldo" << endl;
        cout << "2 = Retirar dinero" << endl;
        cout << "3 = Depositar dinero" << endl;
        cout << "4 = Salir" << endl;
        
        cout << "Ingrese una opción: ";
        cin >> opcion;
        
        switch (opcion) {
            case 1:
                cout << "Su saldo actual es: $" << saldo << endl;
                break;
                
            case 2:
                double montoRetirar;
                cout << "Ingrese la cantidad a retirar: $";
                cin >> montoRetirar;
                if (saldo >= montoRetirar) {
                    saldo -= montoRetirar;
                    cout << "Retiro exitoso. Su saldo actual es: $" << saldo << endl;
                } else {
                    cout << "Saldo insuficiente." << endl;
                }
                break;
                
            case 3:
                double montoDepositar;
                cout << "Ingrese la cantidad a depositar: $";
                cin >> montoDepositar;
                saldo += montoDepositar;
                cout << "Depósito exitoso. Su saldo actual es: $" << saldo << endl;
                break;
                
            case 4:
                cout << "Gracias por utilizar nuestro servicio." << endl;
                return 0;
                
            default:
                cout << "Opción incorrecta, ingrese un número correcto." << endl;
                break;
        }
    }

    return 0;
}
