#include <iostream>
#include <vector>
#include <algorithm>
#include <set>

using namespace std;

void solve() {
    int n;
    cin >> n;
    
    vector<long long> a(n), b(n);
    for (int i = 0; i < n; ++i) cin >> a[i];
    for (int i = 0; i < n; ++i) cin >> b[i];

    if (n == 1) {
        cout << 0 << "\n";
        return;
    }

    // Guardamos los precios disponibles
    multiset<long long> items;
    for (int i = 0; i < n; ++i) {
        items.insert(a[i]);
    }

    // Ordenamos a los compradores por presupuesto ascendente
    vector<long long> buyers = b;
    sort(buyers.begin(), buyers.end());

    int transactions = 0;

    // Estrategia Greedy: Para cada comprador, asignar el item más caro posible
    for (int i = 0; i < n; ++i) {
        auto it = items.upper_bound(buyers[i]);
        if (it != items.begin()) {
            --it; // El mayor elemento <= buyers[i]
            items.erase(it);
            transactions++;
        }
    }

    cout << transactions << "\n";
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int t;
    cin >> t;
    while (t--) {
        solve();
    }
    
    return 0;
}