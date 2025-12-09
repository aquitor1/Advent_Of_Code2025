#include <bits/stdc++.h>
using namespace std;

/*
   Advent of Code 2025 – Día 7
   En este problema el haz avanza por el mapa y cuando
   encuentra un '^' se divide en dos ramas nuevas.
   Lo resolví con una función recursiva típica de divide
   y vencerás, explorando cada ramificación.

   Para no visitar dos veces la misma casilla uso un set
   de posiciones ya procesadas.
*/

vector<string> mapa;
unordered_set<long long> visto;

int H, W;

// Codifica una posición (r,c) en un único número para usarlo en el set
long long cod(int r, int c) {
    return ( (long long) r << 32 ) | (unsigned long long) c;
}

// DFS recursivo que simula el trayecto del haz
int explorar(int r, int c) {
    // Comprobar límites del mapa
    if (r < 0 || r >= H || c < 0 || c >= W) return 0;

    long long key = cod(r, c);
    if (visto.count(key)) return 0;   // ya lo procesé antes
    visto.insert(key);

    char celda = mapa[r][c];

    if (celda == '.') {
        // el haz sigue bajando tal cual
        return explorar(r + 1, c);
    }

    if (celda == '^') {
        // aquí el haz se divide
        int total = 1; // cuenta esta división
        total += explorar(r + 1, c - 1);
        total += explorar(r + 1, c + 1);
        return total;
    }

    // cualquier otro carácter → avanza hacia abajo
    return explorar(r + 1, c);
}

// carga del input
vector<string> leerMapa() {
    vector<string> v;
    string s;
    while (getline(cin, s)) {
        if (!s.empty()) v.push_back(s);
    }
    return v;
}

// busca la S inicial
pair<int,int> buscarInicio() {
    for (int r = 0; r < H; r++) {
        for (int c = 0; c < W; c++) {
            if (mapa[r][c] == 'S') return {r, c};
        }
    }
    return {-1, -1};
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    mapa = leerMapa();
    H = mapa.size();
    W = H ? mapa[0].size() : 0;

    auto inicio = buscarInicio();
    if (inicio.first == -1) {
        cout << 0 << "\n";
        return 0;
    }

    // el haz arranca moviéndose hacia abajo desde la S
    int resultado = explorar(inicio.first + 1, inicio.second);

    cout << resultado << "\n";
    return 0;
}
