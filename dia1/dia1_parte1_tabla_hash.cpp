#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    const int MOD = 100;
    int pos = 50; // posición inicial
    unordered_map<int,long long> freq;
    freq.reserve(128);

    string instr;
    long long total_instructions = 0;

    while (cin >> instr) {
        if (instr.size() < 2) continue;

        char dir = instr[0];
        long long dist = 0;

        // Parseamos el número, digito a dígito
        for (size_t i = 1; i < instr.size(); ++i) {
            char c = instr[i];
            if (c >= '0' && c <= '9') {
                dist = dist * 10 + (c - '0');
            } else break;
        }

        int d = int(dist % MOD);

        if (dir == 'L') {
            pos = (pos - d) % MOD;
            if (pos < 0) pos += MOD;
        } else { // 'R'
            pos = (pos + d) % MOD;
        }

        freq[pos] += 1;
        ++total_instructions;
    }

    long long password = 0;
    auto it = freq.find(0);
    if (it != freq.end()) password = it->second;

    cout << "Total instrucciones leidas: " << total_instructions << "\n";
    cout << "Veces que la ruleta apuntó a 0: " << password << "\n";

    return 0;
}


