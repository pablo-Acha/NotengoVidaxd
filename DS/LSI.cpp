#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

// Estructura del Binary Indexed Tree para MÁXIMOS
struct BIT {
    int size;
    vector<int> tree;

    BIT(int n) : size(n), tree(n + 1, 0) {}

    // Actualiza la posición 'idx' con el valor 'val' si es mayor al existente
    void updateMax(int idx, int val) {
        for (; idx <= size; idx += idx & -idx) {
            tree[idx] = max(tree[idx], val);
        }
    }

    // Consulta el valor máximo en el rango [1, idx]
    int queryMax(int idx) {
        int max_val = 0;
        for (; idx > 0; idx -= idx & -idx) {
            max_val = max(max_val, tree[idx]);
        }
        return max_val;
    }
};

int getLIS(vector<int>& arr) {
    int n = arr.size();
    if (n == 0) return 0;

    // --- 1. Compresión de Coordenadas ---
    vector<int> sorted_arr = arr;
    sort(sorted_arr.begin(), sorted_arr.end());
    // Eliminar duplicados para asignar un rango 1..M
    sorted_arr.erase(unique(sorted_arr.begin(), sorted_arr.end()), sorted_arr.end());

    auto get_compressed_val = [&](int val) {
        // lower_bound devuelve iterador en base 0, sumamos 1 para base 1 (requerido por BIT)
        return lower_bound(sorted_arr.begin(), sorted_arr.end(), val) - sorted_arr.begin() + 1;
    };

    int m = sorted_arr.size(); // Número de elementos únicos
    BIT bit(m);

    // --- 2. Procesamiento del LIS usando el BIT ---
    for (int num : arr) {
        int x = get_compressed_val(num);
        
        // Consultamos el máximo en [1, x - 1] (estrictamente menores que x)
        int best = bit.queryMax(x - 1) + 1;
        
        // Actualizamos la posición x con la mejor longitud lograda
        bit.updateMax(x, best);
    }

    // --- 3. El resultado es el máximo global en el BIT ---
    return bit.queryMax(m);
}

int main() {
    vector<int> arr = {10, 9, 2, 5, 3, 7, 101, 18};

    int lis = getLIS(arr);

    cout << "Longitud de la LIS: " << lis << endl; // Resultado esperado: 4 ([2, 3, 7, 101])

    return 0;
}