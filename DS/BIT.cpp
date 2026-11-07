#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef vector<ll> vll;
typedef  pair<int,int> pii;
typedef  pair<ll,ll> pll;
typedef  vector<int> vi;

#define all(x) (x).begin(), (x).end()

class BIT {
private:
    std::vector<int> tree;
    int n;

public:
    // Inicializa el BIT con un tamaño específico
    BIT(int size) {
        n = size;
        tree.assign(n + 1, 0); // El BIT usa indexación basada en 1
    }

    // Agrega 'val' al elemento en el índice 'idx' (indexado en 1)
    void update(int idx, int val) {
        cout<<"-----\n";
        cout<<val<<": \n";
        for (; idx <= n; idx += idx & -idx) {
            cout<<idx<<" ";
            tree[idx] += val;
        }
        cout<<"\n";
    }

    // Devuelve la suma acumulada desde el índice 1 hasta 'idx'
    int query(int idx) {
        int sum = 0;
        for (; idx > 0; idx -= idx & -idx) {
            sum += tree[idx];
        }
        return sum;
    }

    // Devuelve la suma en el rango [l, r] (indexado en 1)
    int queryRange(int l, int r) {
        if (l > r) return 0;
        return query(r) - query(l - 1);
    }
};


int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    vector<int> arr = {3, 2, -1, 6, 5, 4, -3, 3, 7, 2};
    int n = arr.size();

    BIT bit(n);

    // Construcción eficiente en O(n) en lugar de O(n log n)
    // Se puede hacer pasando el array y acumulando hacia los padres inmediatos
    for (int i = 1; i <= n; ++i) {
        bit.update(i, arr[i - 1]);
    }

    std::cout << "Suma del rango [1, 5]: " << bit.queryRange(1, 5) << "\n"; // Esperado: 15

    // Modificar el elemento en el índice 3 (sumarle 3)
    bit.update(3, 3); 

    std::cout << "Suma del rango [1, 5] tras actualización: " << bit.queryRange(1, 5) << "\n"; // Esperado: 18


    

    return 0;
}