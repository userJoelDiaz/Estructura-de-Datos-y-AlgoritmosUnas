#include <iostream>
using namespace std;

int main() {
    double compra, descuento, total;

    // Ingresar el monto de la compra
    cout << "Ingrese el monto de la compra: ";
    cin >> compra;

    // Verificar si la compra está en el rango del descuento
    if (compra >= 1000) {
        // Calcular el descuento
        descuento = compra * 0.10; // 10% de descuento
        total = compra - descuento;
        cout << "Monto a pagar con descuento del 10%: $" << total << endl;
    } else if (compra >= 500) {
        // Calcular el descuento
        descuento = compra * 0.05; // 5% de descuento
        total = compra - descuento;
        cout << "Monto a pagar con descuento del 5%: $" << total << endl;
    } else {
        cout << "No se aplica ningún descuento. Monto a pagar: $" << compra << endl;
    }

    return 0;
}
