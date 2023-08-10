#include <iostream>

int main() {
    double lado1, lado2, lado3;

    std::cout << "Ingrese la longitud del primer lado: ";
    std::cin >> lado1;

    std::cout << "Ingrese la longitud del segundo lado: ";
    std::cin >> lado2;

    std::cout << "Ingrese la longitud del tercer lado: ";
    std::cin >> lado3;

    if (lado1 == lado2 && lado2 == lado3) {
        std::cout << "Es un triángulo equilátero." << std::endl;
    } else if (lado1 == lado2 || lado1 == lado3 || lado2 == lado3) {
        std::cout << "Es un triángulo isósceles." << std::endl;
    } else {
        std::cout << "Es un triángulo escaleno." << std::endl;
    }

    return 0;
}
