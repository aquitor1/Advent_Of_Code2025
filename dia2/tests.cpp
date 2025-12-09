#include <cassert>
#include <iostream>
#include "main.cpp"

int main() {
    assert(generarPPenRango(11,22).size() == 2);
    assert(generarPPenRango(95,115).size() == 1);

    cout << "Todos los tests pasaron correctamente.\n";
    return 0;
}

