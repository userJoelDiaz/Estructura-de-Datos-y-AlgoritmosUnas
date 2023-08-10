#include <iostream>
#include <string>
using namespace std;

int main() {    
 float nota1, nota2, nota3, promedio; 
 string estado;

    // Ingresar las notas de los exámenes    
    cout << "Ingresa la nota del primer examen (0 a 20): ";     
    cin >> nota1;    
    cout << "Ingresa la nota del segundo examen (0 a 20): ";     
    cin >> nota2;    
    cout << "Ingresa la nota del tercer examen (0 a 20): ";     
    cin >> nota3; 
 
    // Calcular el promedio     
    promedio = (nota1 + nota2 + nota3) / 3; 
 
    // Verificar el estado académico     string estado;     
    if (promedio >= 10.5) {         
        estado = "Aprobado"; 
    } else { 
        estado = "Desaprobado"; 
    } 
    // Mostrar el promedio y el estado académico del estudiante     
    cout << "Promedio: " << promedio << endl;     cout << "Estado académico: " << estado << endl;     
    return 0; 
} 

 
