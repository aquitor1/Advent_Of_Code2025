

#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    const int MOD = 100;
    int pos = 50; // posición inicial
    long long total_instructions = 0;
    long long end_at_zero_count = 0; // Parte 1 (si quieres)
    long long passes_through_zero = 0; // Parte 2 (resultado final)

    string instr;
    while (cin >> instr) {
        if (instr.size() < 2) continue;
        char dir = instr[0];
        // Parsear distancia robustamente
        long long dist = 0;
        for (size_t i = 1; i < instr.size(); ++i) {
            char c = instr[i];
            if (c >= '0' && c <= '9') dist = dist*10 + (c - '0');
            else break;
        }

        // primer k (número de clicks hasta la primera vez que se llega a 0)
        int first_k;
        if (dir == 'R') {
            first_k = (MOD - (pos % MOD)) % MOD;
            if (first_k == 0) first_k = MOD;
        } else { // 'L'
            first_k = pos % MOD;
            if (first_k == 0) first_k = MOD;
        }

        if (first_k <= dist) {
            passes_through_zero += 1 + ( (dist - first_k) / MOD );
        }

        // actualizar posición final (euclidiano, con signo controlado)
        int d_mod = int(dist % MOD);
        if (dir == 'R') {
            pos = (pos + d_mod) % MOD;
        } else {
            pos = (pos - d_mod) % MOD;
            if (pos < 0) pos += MOD;
        }

        if (pos == 0) end_at_zero_count++;

        ++total_instructions;
    }

    cout << "Total instrucciones leidas: " << total_instructions << "\n";
    cout << "Veces que la ruleta apuntó a 0 (al final de rotacion) : " << end_at_zero_count << "\n";
    cout << "Veces que la ruleta apuntó a 0 (durante cualquier click) : " << passes_through_zero << "\n";

    return 0;
}


