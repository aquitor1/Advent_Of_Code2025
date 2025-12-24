DIA 8 

#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>

using namespace std;

/*nodo del grafo*/
struct Node {
    int x, y, z;
};

/*aristta*/
struct Edge {
    int u, v;       // nodos que conecta
    double dist;    // distancia entre ellos
};

/*ordenar aristas por distancia */
bool compareEdges(const Edge& a, const Edge& b) {
    return a.dist < b.dist;
}

/* cuentarel tamaño de una componente*/
void dfs(int v, vector<vector<int> >& adj, vector<bool>& visited, int& count) {
    visited[v] = true;
    count++;

    for (size_t i = 0; i < adj[v].size(); i++) {
        int to = adj[v][i];
        if (!visited[to]) {
            dfs(to, adj, visited, count);
        }
    }
}

int main() {
    vector<Node> nodes;
    int x, y, z;

    // Leer input
    while (cin >> x) {
        cin.ignore(); // coma
        cin >> y;
        cin.ignore();
        cin >> z;
        nodes.push_back({x, y, z});
    }

    int n = nodes.size();
    vector<Edge> edges;

    /*construccion de las aristas del grafo 
    */
    for (int i = 0; i < n; i++) {
        for (int j = i + 1; j < n; j++) {
            double dx = nodes[i].x - nodes[j].x;
            double dy = nodes[i].y - nodes[j].y;
            double dz = nodes[i].z - nodes[j].z;

            double dist = sqrt(dx*dx + dy*dy + dz*dz); //aqui esta la form a la distancia de 2 pts en el plano de 3 dimensiones
            edges.push_back({i, j, dist});
        }
    }

    // ordinacion
    sort(edges.begin(), edges.end(), compareEdges);

    
    vector<vector<int> > adj(n);

    /*solo las 1000 conexiones más cortas
    */
    for (int i = 0; i < 1000 && i < (int)edges.size(); i++) {
        int u = edges[i].u;
        int v = edges[i].v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    /*calc las componentes conexas con DFS
    */
    vector<bool> visited(n, false);
    vector<int> componentSizes;

    for (int i = 0; i < n; i++) {
        if (!visited[i]) {
            int count = 0;
            dfs(i, adj, visited, count);
            componentSizes.push_back(count);
        }
    }

    // de mayor a menor
    sort(componentSizes.begin(), componentSizes.end(), greater<int>());

    // producto de las tres mayores componentes
    long long result = 1;
    for (int i = 0; i < 3; i++) {
        result *= componentSizes[i];
    }

    cout << result << endl;

    return 0;
}
