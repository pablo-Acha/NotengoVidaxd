#include <iostream>
#include <vector>

using namespace std;

const int MAXN = 100;
vector<int> adj[MAXN];
int tin[MAXN], tout[MAXN];
vector<int> tour_order; // Muestra el arreglo aplanarado (1D)
int timer = 0;

void dfs_range(int u, int p) {
    tin[u] = ++timer;        // Instantánea de entrada
    tour_order.push_back(u);  // Colocamos el nodo en la posición actual del arreglo

    for (int v : adj[u]) {
        if (v != p) {
            dfs_range(v, u);
        }
    }

    tout[u] = timer;         // Instantánea de salida (cubre a todos los descendientes)
}

int main() {
    // Definir aristas del árbol de ejemplo
    adj[1] = {2, 3}; adj[2] = {1, 4, 5};
    adj[3] = {1};    adj[4] = {2};       adj[5] = {2};

    dfs_range(1, 0);

    cout << "=== VERSIÓN 1: RANGOS (tin / tout) ===\n";
    cout << "Orden aplanado (Arreglo 1D): ";
    for (int x : tour_order) cout << x << " ";
    cout << "\n\nIntervalos por subárbol:\n";

    for (int i = 1; i <= 5; ++i) {
        cout << "Nodo " << i << " -> Intervalo en el arreglo: [" 
             << tin[i] << ", " << tout[i] << "]\n";
    }
    return 0;
}