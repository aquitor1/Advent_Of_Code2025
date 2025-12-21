#include <bits/stdc++.h>
using namespace std;

unordered_map<string, vector<string>> grafo;
unordered_set<string> visitado;
int total = 0;

void buscar(string nodo) {
    if (nodo == "out") {
        total++;
        return;
    }
    if (visitado.count(nodo)) return;
    
    visitado.insert(nodo);
    
    for (string siguiente : grafo[nodo]) {
        buscar(siguiente);
    }
    
    visitado.erase(nodo);
}

int main() {
    string linea;
    
    while (getline(cin, linea)) {
        if (linea.empty()) continue;
        
        size_t dos_puntos = linea.find(':');
        string desde = linea.substr(0, dos_puntos);
        string resto = linea.substr(dos_puntos + 2);
        
        istringstream ss(resto);
        string hacia;
        while (ss >> hacia) {
            grafo[desde].push_back(hacia);
        }
    }
    
    buscar("you");
    
    cout << total << endl;
    
    return 0;
}
