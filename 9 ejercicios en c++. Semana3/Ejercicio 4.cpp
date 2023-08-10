#include <iostream>
#include <iomanip> // Para formatear la salida

int main() {
    const double COSTO_POR_KG = 10.0; // Costo por kilogramo en dólares

    std::string pais;
    double peso, costoTotal;

    // Solicitar información al usuario
    std::cout << "Ingrese el país de destino: ";
    std::cin >> pais;

    std::cout << "Ingrese el peso del paquete en kg: ";
    std::cin >> peso;

    // Calcular el costo total
    costoTotal = COSTO_POR_KG * peso;

    // Aplicar tarifas específicas según el país
    if (pais == "EEUU") {
        costoTotal += 5.0;
    } else if (pais == "Canada") {
        costoTotal += 8.0;
    } else if (pais == "Mexico") {
        costoTotal += 12.0;
    } else {
        costoTotal += 15.0; // Tarifa predeterminada para otros países
    }

    // Mostrar el resultado
    std::cout << std::fixed << std::setprecision(2);
    std::cout << "El costo de envío a " << pais << " es $" << costoTotal << std::endl;

    return 0;
}
