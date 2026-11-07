#include <iostream>
#include <vector>

class FenwickTreeOrder {
private:
    std::vector<int> tree;
    int n;
    int LOG; // La mayor potencia de 2 tal que 2^LOG <= n

public:
    FenwickTreeOrder(int size) {
        n = size;
        tree.assign(n + 1, 0);
        
        // Calculamos el LOG necesario para los saltos binarios
        LOG = 0;
        while ((1 << (LOG + 1)) <= n) {
            LOG++;
        }
    }

    // Inserta o elimina (frecuencia)
    void update(int idx, int val) {
        for (; idx <= n; idx += idx & -idx) {
            tree[idx] += val;
        }
    }

    // Encuentra el k-ésimo elemento en O(log n) usando Binary Lifting
    int findKth(int k) {
        int pos = 0;
        for (int pw = LOG; pw >= 0; pw--) {
            int next = pos + (1 << pw);
            // Si el índice es válido y los elementos acumulados son menos que k
            if (next <= n && tree[next] < k) {
                pos = next;       // Damos el salto
                k -= tree[next];  // Restamos los elementos que ya saltamos
            }
        }
        // pos termina en el elemento justo antes, por lo que el k-ésimo es pos + 1
        return pos + 1;
    }
};

int main() {
    // Supongamos que manejamos números del 1 al 10
    FenwickTreeOrder bit(10);

    // Insertamos los números: 3, 5, 3, 8, 2
    // Conjunto ordenado en mente: {2, 3, 3, 5, 8}
    bit.update(2, +1);
    bit.update(3, +1);
    bit.update(3, +1);
    bit.update(5, +1);
    bit.update(8, +1);

    std::cout << "--- Buscando el k-esimo elemento ---\n";
    std::cout << "1 elemento mas chico (k=1): " << bit.findKth(1) << "\n"; // Esperado: 2
    std::cout << "2 elemento mas chico (k=2): " << bit.findKth(2) << "\n"; // Esperado: 3
    std::cout << "3 elemento mas chico (k=3): " << bit.findKth(3) << "\n"; // Esperado: 3 (el otro 3)
    std::cout << "4 elemento mas chico (k=4): " << bit.findKth(4) << "\n"; // Esperado: 5
    std::cout << "5 elemento mas chico (k=5): " << bit.findKth(5) << "\n"; // Esperado: 8

    std::cout << "\n--- Eliminando un 3 del conjunto ---\n";
    bit.update(3, -1); 
    // Conjunto ahora: {2, 3, 5, 8}

    std::cout << "Nuevo 3 elemento mas chico (k=3): " << bit.findKth(3) << "\n"; // Esperado: 5

    return 0;
}