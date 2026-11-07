#include <iostream>
#include <vector>

using namespace std;

const int MAXN = 100;
vector<int> adj[MAXN];
vector<int> euler_tour; // Guarda la secuencia de nodos visitados
vector<int> depth_tour; // Guarda la profundidad asociada a cada paso
int first_appearance[MAXN];
int depth[MAXN];

void dfs_full(int u, int p, int d) {
    depth[u] = d;
    first_appearance[u] = euler_tour.size(); // Primera vez que vemos este nodo
    
    euler_tour.push_back(u);
    depth_tour.push_back(d);

    for (int v : adj[u]) {
        if (v != p) {
            dfs_full(v, u, d + 1);
            // AL REGRESAR DEL HIJO: Volvemos a anotar al nodo padre
            euler_tour.push_back(u);
            depth_tour.push_back(d);
        }
    }
}

int main() {
    // Mismo árbol de ejemplo
    adj[1] = {2, 3}; adj[2] = {1, 4, 5};
    adj[3] = {1};    adj[4] = {2};       adj[5] = {2};

    dfs_full(1, 0, 0);

    cout << "=== VERSION 2: RECORRIDO COMPLETO (~2N) ===\n";
    cout << "Euler Tour (Nodos):       ";
    for (int x : euler_tour) cout << x << " ";
    cout << "\nProfundidad equivalente: ";
    for (int d : depth_tour) cout << d << " ";
    cout << "\n\n";

    // Ejemplo de LCA entre nodo 4 y nodo 5:
    int pos4 = first_appearance[4];
    int pos5 = first_appearance[5];
    cout << "Para hallar LCA(4, 5):\n";
    cout << "Primera aparicion de 4 en indice: " << pos4 << "\n";
    cout << "Primera aparicion de 5 en indice: " << pos5 << "\n";
    cout << "-> El LCA es el nodo con la MENOR profundidad en ese sub-rango del tour.\n";

    return 0;
}