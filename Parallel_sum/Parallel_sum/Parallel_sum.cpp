// Parallel_sum.cpp : Este archivo contiene la función "main". La ejecución del programa comienza y termina ahí.
//

#include <iostream>
#include <omp.h> // Libreria de OMP 

#define N 80000  // Cantidad de elementos a manejar en los arreglos 
#define chunck 100 // Tamaño de los pedazos de los arreglos 
#define mostrar 10 // Cantidad de datos a imprimir 

void imprimeArreglo(float* d); // Variable para imprimir los arreglos se define despues del main 

int main()
{

    std::cout << "Sumando arreglos en paralelo!\n";
    float a[N], b[N], c[N]; // Declaracion de variables
    int i; // iterador

    for (i = 0; i < N; i++) // for loop
    {
        a[i] = i * 10;  
        b[i] = (i + 3) * 3.45;
    }
    int pedazos = chunck; // Asignacion del tamaño de arreglo a la var entera pedazos



    #pragma omp parallel for shared(a,b,c, pedazos) private(i) schedule(static, pedazos)
    for (i = 0; i < N; i++) // For loop addition
        c[i] = a[i] + b[i];



    // Se muestran parate de los pedazos de los arreglos asi como su resultado despues de usar el for paralelo 
    std::cout << "Imprimiendo los primeros " << mostrar << " valores del arreglo a " << std::endl;
    imprimeArreglo(a);
    std::cout << "Imprimiendo los primeros " << mostrar << " valores del arreglo b " << std::endl;
    imprimeArreglo(b);
    std::cout << "Imprimiendo los primeros " << mostrar << " valores del arreglo c " << std::endl;
    imprimeArreglo(c);
    std::cout << std::endl;

}

void imprimeArreglo(float* d)
{
    for (int x = 0; x < mostrar; x++) // ciclo for para imprimir los valores de los arreglos.
        std::cout << d[x] << " - ";
    std::cout << std::endl;
}


// Ejecutar programa: Ctrl + F5 o menú Depurar > Iniciar sin depurar
// Depurar programa: F5 o menú Depurar > Iniciar depuración

// Sugerencias para primeros pasos: 1. Use la ventana del Explorador de soluciones para agregar y administrar archivos
//   2. Use la ventana de Team Explorer para conectar con el control de código fuente
//   3. Use la ventana de salida para ver la salida de compilación y otros mensajes
//   4. Use la ventana Lista de errores para ver los errores
//   5. Vaya a Proyecto > Agregar nuevo elemento para crear nuevos archivos de código, o a Proyecto > Agregar elemento existente para agregar archivos de código existentes al proyecto
//   6. En el futuro, para volver a abrir este proyecto, vaya a Archivo > Abrir > Proyecto y seleccione el archivo .sln
