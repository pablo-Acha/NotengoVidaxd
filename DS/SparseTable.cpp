#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>

using namespace std;

const int MAXN = 200005;
const int LOGN = 18; // Suficiente para N hasta 200,000 (2^18 = 262,144)

int st[LOGN][MAXN];
int log_table[MAXN];

// 1. Precalculamos los logaritmos en O(N) para evitar std::log2 (que es lento)
void precalculate_logs(int n) {
    log_table[1] = 0;
    for (int i = 2; i <= n; i++) {
        log_table[i] = log_table[i / 2] + 1;
    }
}

// 2. Construcción de la Sparse Table en O(N log N)
void build_sparse_table(const vector<int>& arr) {
    int n = arr.size();
    
    // Caso base: Rangos de tamaño 2^0 = 1
    for (int i = 0; i < n; i++) {
        st[0][i] = arr[i];
    }

    // Programación dinámica para tamaños 2^k
    for (int k = 1; (1 << k) <= n; k++) {
        for (int i = 0; i + (1 << k) <= n; i++) {
            // Para máximo usa max(), para GCD usa __gcd()
            st[k][i] = min(st[k - 1][i], st[k - 1][i + (1 << (k - 1))]);
        }
    }
}

// 3. Consulta en O(1)
int query_min(int L, int R) {
    int len = R - L + 1;
    int k = log_table[len];
    
    // Combinamos los dos bloques superpuestos
    return min(st[k][L], st[k][R - (1 << k) + 1]);
}

int main() {
    // Optimización de I/O
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    vector<int> arr = {7, 2, 3, 0, 5, 10, 3, 12, 18};
    int n = arr.size();

    precalculate_logs(n);
    build_sparse_table(arr);

    // Ejemplo de consultas (índices 0-based):
    cout << "Minimo en [0, 4]: " << query_min(0, 4) << "\n"; // Rango [7, 2, 3, 0, 5] -> 0
    cout << "Minimo en [4, 7]: " << query_min(4, 7) << "\n"; // Rango [5, 10, 3, 12] -> 3
    cout << "Minimo en [7, 8]: " << query_min(7, 8) << "\n"; // Rango [12, 18] -> 12

    return 0;
}