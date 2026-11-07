#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

struct FenwickTree {
    int size;
    vector<int> tree;

    FenwickTree(int n) : size(n), tree(n + 1, 0) {}

    void add(int idx, int val) {
        for (; idx <= size; idx += idx & -idx) {
            tree[idx] += val;
        }
    }

    int query(int idx) {
        int sum = 0;
        for (; idx > 0; idx -= idx & -idx) {
            sum += tree[idx];
        }
        return sum;
    }
};

vector<int> menoresALaDerecha(const vector<int>& arr) {
    int n = arr.size();
    vector<int> resultado(n, 0);
    if (n == 0) return resultado;

    // 1. Compresión de coordenadas
    vector<int> temp = arr;
    sort(temp.begin(), temp.end());
    temp.erase(unique(temp.begin(), temp.end()), temp.end());

    // 2. Fenwick Tree
    FenwickTree bit(temp.size());

    // Recorremos de DERECHA a IZQUIERDA
    for (int i = n - 1; i >= 0; --i) {
        int pos = lower_bound(temp.begin(), temp.end(), arr[i]) - temp.begin() + 1;

        // Guardamos exactamente la respuesta para el índice i
        resultado[i] = bit.query(pos - 1);

        // Insertamos el elemento actual en el Fenwick Tree
        bit.add(pos, 1);
    }

    return resultado;
}

int main() {
    vector<int> arr = {1,5,5, 2, 4, 1};

    vector<int> ans = menoresALaDerecha(arr);

    cout << "Arreglo original:  ";
    for (int x : arr) cout << x << " ";
    cout << "\nMenores a la derecha: ";
    for (int x : ans) cout << x << " ";
    cout << endl;

    return 0;
}