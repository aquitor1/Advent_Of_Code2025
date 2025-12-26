#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <cstdlib>

using namespace std;

/* La clave será un entero (ingredient ID)*/

// Tamaño de la tabla hash 
const int HASH_SIZE = 10007;

//Función hash
int hashFunction(int key) {
    return key % HASH_SIZE;
}

int main() {
    ifstream file("input.txt");

    if (!file.is_open()) {
        cout << "Error al abrir el archivo." << endl;
        return 1;
    }

    /* al ser un vector de vectores; cada posición puede contener varios IDs (encadenamiento).
    */
    vector< vector<int> > hashTable(HASH_SIZE);

    string line;

 
 //     lee rangos d los ids  
   
    while (getline(file, line)) {
        // Línea vacía => fin de rangos
        if (line == "")
            break;

 // buscamos el guion del rango
        size_t dashPos = line.find('-');

        int start = atoi(line.substr(0, dashPos).c_str());
        int end   = atoi(line.substr(dashPos + 1).c_str());

        /*
            Insertar los ids del rango en la tabla  */
        for (int id = start; id <= end; id++) {
            int index = hashFunction(id);
            hashTable[index].push_back(id);
        }
    }

    /* leer ids disponibles*/
    int freshCount = 0;

    while (getline(file, line)) {
        if (line == "")
            continue;

        int id = atoi(line.c_str());
        int index = hashFunction(id);

        bool isFresh = false;

        /*
            buscamos el id en la lista de su posición hash
        */
        for (size_t i = 0; i < hashTable[index].size(); i++) {
            if (hashTable[index][i] == id) {
                isFresh = true;
                break;
            }
        }

        if (isFresh)
            freshCount++;
    }

    file.close();

    /* respuesta */
    cout << "Numero de ingredientes frescos: "
         << freshCount << endl;

    return 0;
}
