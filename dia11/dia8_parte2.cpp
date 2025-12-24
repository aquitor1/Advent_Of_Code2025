#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>
#include <numeric>

using namespace std;

/* nodo del grafo */
struct Node {
    int x, y, z;
};

/* arista */
struct Edge {
    int u, v;       // nodos que conecta
    double dist;    // distancia entre ellos
};

/* ordenar aristas por distancia xq queremos comparar distancias luego*/
bool compareEdges(const Edge& a, const Edge& b) {
    return a.dist < b.dist;
}

/* Union-Find (Disjoint Set Union) para manejar componentes */
class DSU {
private:
    vector<int> parent;
    vector<int> rank;
    int components;
    
public:
    DSU(int n) {
        parent.resize(n);    //para actualizar tamanyo
        rank.resize(n, 0);
        components = n;
        
        // cada nodo es su propio padre inicialmente
        iota(parent.begin(), parent.end(), 0);
    }
    
    int find(int x) {
        if (parent[x] != x) {
            parent[x] = find(parent[x]); // compresión de camino
        }
        return parent[x];
    }
    
    bool unite(int x, int y) {
        int rootX = find(x);
        int rootY = find(y);
        
        // si ya están en el mismo conjunto, no hacer nada
        if (rootX == rootY) {
            return false;
        }
        
        // unión por rango
        if (rank[rootX] < rank[rootY]) {
            swap(rootX, rootY);
        }
        
        parent[rootY] = rootX;
        
        if (rank[rootX] == rank[rootY]) {
            rank[rootX]++;
        }
        
        components--;
        return true;
    }
    
    bool allConnected() {
        return components == 1;
    }
    
    int getComponents() {
        return components;
    }
};

int main() {
    vector<Node> nodes;
    int x, y, z;
    
    // leer input
    while (cin >> x) {
        cin.ignore(); // coma
        cin >> y;
        cin.ignore();
        cin >> z;
        nodes.push_back({x, y, z});
    }
    
    int n = nodes.size();
    vector<Edge> edges;
    
    /* construcción de todas las aristas del grafo completo */
    for (int i = 0; i < n; i++) {
        for (int j = i + 1; j < n; j++) {
            double dx = nodes[i].x - nodes[j].x;
            double dy = nodes[i].y - nodes[j].y;
            double dz = nodes[i].z - nodes[j].z;
            
            double dist = sqrt(dx*dx + dy*dy + dz*dz); //la formula de distancia entre 2 puntos en plano de 3 dimensiones
            edges.push_back({i, j, dist});
        }
    }
    
    //ordenar aristas por distancia (de menor a mayor)
    sort(edges.begin(), edges.end(), compareEdges);
    
    // inicializar DSU
    DSU dsu(n);
    
    Edge lastEdge = {-1, -1, 0.0}; // para guardar la última arista que conecto todo
    
    // conectar aristas hasta que todos esten en el mismo circuito
    for (int i = 0; i < (int)edges.size(); i++) {
        int u = edges[i].u;
        int v = edges[i].v;
        
        // intentar unir los conjuntos
        if (dsu.unite(u, v)) {
            // guardar esta arista como posible última
            lastEdge = edges[i];
            
            // verificar si ya todos están conectados
            if (dsu.allConnected()) {
                break;
            }
        }
    }
    
    // calcular el producto de las coordenadas X de la última arista
    if (lastEdge.u != -1 && lastEdge.v != -1) {
        long long result = (long long)nodes[lastEdge.u].x * nodes[lastEdge.v].x;
        cout << result << endl;
    } else {
        cout << "No se pudo conectar todos los nodos" << endl;
    }
    
    return 0;
}
