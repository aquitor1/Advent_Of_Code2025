#include <bits/stdc++.h>
using namespace std;

/*ojo
 estados 
   dp[state] = almacenará eml mínimo número de pulsaciones para alcanzar ese estado desde el estado inicial.

   transición:
       state --(botón b)--> state ^ button_mask[b]

   como todas las transiciones cuestan 1, usamos BFS para calcular dp[] por niveles.
*/



// target_mask: máscara objetivo
// button_masks: lista de máscaras de botones
// n: número de luces


//Leer las lineas de input
void parseLine(const string &line, int &target_mask, vector<int> &button_masks, int &n) {
    //Obtener el patrón entre [ ], el target
    size_t l = line.find('[');//solo positivo 
    size_t r = line.find(']');
    string lights = line.substr(l + 1, r - l - 1);//extrae lo q esta entre []

    n = lights.size();
    target_mask = 0;

    for (int i = 0; i < n; i++) {
        if (lights[i] == '#') {
            target_mask |= (1 << i);
        }
    }//se hace un codigo binario

    // extraer los botones entre ( )
    button_masks.clear();//se reinicia el vector sin ningun dato
    for (size_t pos = 0; pos < line.size(); pos++) {
        if (line[pos] == '(') {
            size_t end = line.find(')', pos);
            string inside = line.substr(pos + 1, end - pos - 1);

            if (!inside.empty()) {
                stringstream ss(inside);
                string token;
                int mask = 0;

                while (getline(ss, token, ',')) {
                    if (!token.empty()) {
                        int idx = stoi(token);
                        mask |= (1 << idx);
                    }
                }
                button_masks.push_back(mask);
            }
            pos = end;
        }
    }
}


// DP para una máquina
int minPresses(int target_mask, const vector<int> &buttons, int n) {
    int max_state = 1 << n;
    vector<int> dist(max_state, -1);

    queue<int> q;// creamos una cola de enteros
    dist[0] = 0;
    q.push(0);

    while (!q.empty()) {
        int s = q.front(); q.pop();

        if (s == target_mask)
            return dist[s];

        for (int bm : buttons) {
            int t = s ^ bm;
            if (dist[t] == -1) {
                dist[t] = dist[s] + 1;
                q.push(t);
            }
        }
    }

    return -1; // si no se puede (en teoría no debería pasar)
}


int main() {
    
    string line;
    long long total = 0;

    while (getline(cin, line)) {
        if (line.empty()) continue;

        int target_mask, n;
        vector<int> buttons;

        parseLine(line, target_mask, buttons, n);

        int presses = minPresses(target_mask, buttons, n);
        total += presses;
    }

    cout << total << "\n";
    return 0;
}

