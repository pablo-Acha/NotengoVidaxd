#include <iostream>
#include <vector>
#include <algorithm>
#include <tuple>

using namespace std;

typedef long long ll;
typedef vector<ll> vll;

#define all(x) (x).begin(), (x).end()

// Estructura de Persona para mayor claridad
struct Person {
    ll a, v;
    int id; // Índice original (0-based)
};

// Comparador personalizado CRÍTICO para LIS 2D
bool comp(const Person& p1, const Person& p2) {
    if (p1.a != p2.a) return p1.a < p2.a; // De menor a mayor por 'a'
    return p1.v > p2.v;                   // De MAYOR a MENOR por 'v'
}

struct BIT {
    int n;
    vector<pair<int, int>> tree;

    BIT(int n) : n(n), tree(n + 1, {0, -1}) {}

    void updateMax(int idx, int len, int original_idx) {
        for (; idx <= n; idx += idx & -idx) {
            if (len > tree[idx].first) {
                tree[idx] = {len, original_idx};
            }
        }
    }

    pair<int, int> queryMax(int idx) {
        pair<int, int> res = {0, -1};
        for (; idx > 0; idx -= idx & -idx) {
            if (tree[idx].first > res.first) {
                res = tree[idx];
            }
        }
        return res;
    }
};

int main() {
    // Redirección de Archivos
    freopen("people.in", "r", stdin);
    freopen("people.out", "w", stdout);

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    if (!(cin >> n)) return 0;

    vector<Person> arr(n);
    vll v_vals(n);

    for (int i = 0; i < n; i++) {
        cin >> arr[i].a >> arr[i].v;
        arr[i].id = i + 1; // Guardamos el id 1-based directamente
        v_vals[i] = arr[i].v;
    }

    // 1. Ordenamos con el comparador correcto
    sort(all(arr), comp);

    // 2. Compresión de coordenadas únicamente para 'v'
    sort(all(v_vals));
    v_vals.erase(unique(all(v_vals)), v_vals.end());

    auto get_compressed_v = [&](ll val) {
        return lower_bound(all(v_vals), val) - v_vals.begin() + 1;
    };

    int m = v_vals.size();
    BIT bit(m);

    vector<int> parent(n, -1);
    int max_len = 0;
    int last_idx = -1;

    // 3. Procesamiento del LIS
    for (int i = 0; i < n; ++i) {
        int x = get_compressed_v(arr[i].v);

        auto [best_len, prev_idx] = bit.queryMax(x - 1);

        int current_len = best_len + 1;
        parent[i] = prev_idx;

        bit.updateMax(x, current_len, i);

        if (current_len > max_len) {
            max_len = current_len;
            last_idx = i;
        }
    }

    // 4. Reconstrucción con las IDs originales
    vll res;
    int curr = last_idx;
    while (curr != -1) {
        res.push_back(arr[curr].id);
        curr = parent[curr];
    }
    reverse(all(res));

    // Salida
    cout << max_len << "\n";
    for (int i = 0; i < (int)res.size(); i++) {
        cout << res[i] << (i == (int)res.size() - 1 ? "" : " ");
    }
    cout << "\n";

    return 0;
}