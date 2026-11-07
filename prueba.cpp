#include <iostream>
#include <string>
#include <unordered_map>
#include <iomanip>

using namespace std;

void pruebaDeEscritorio() {
    int n;
    string a;
    
    cout << "Ingrese n (longitud): ";
    cin >> n;
    cout << "Ingrese la cadena de digitos: ";
    cin >> a;

    unordered_map<long long, long long> d;
    
    // Estado inicial antes del bucle
    d[0] = 1;
    long long res = 0;
    long long s = 0;

    cout << "\n========================================================================================\n";
    cout << " ESTADO INICIAL: d[0] = 1 | s = 0 | res = 0\n";
    cout << "========================================================================================\n\n";

    // Encabezado de la tabla
    cout << left 
         << setw(5)  << "i"
         << setw(8)  << "a[i]"
         << setw(10) << "Suma (s)"
         << setw(16) << "x = s - i - 1"
         << setw(12) << "d[x] prev."
         << setw(12) << "Nuevo res"
         << setw(16) << "Nuevo d[x]"
         << "\n";
    cout << string(80, '-') << "\n";

    for (int i = 0; i < n; i++) {
        int digito = a[i] - '0';
        s += digito;
        long long x = s - i - 1;

        long long freq_previa = d[x]; // Ocurrencias antes de este paso
        res += freq_previa;            // Se suman las combinaciones formadas
        d[x]++;                        // Se registra este nuevo prefijo

        // Imprimir la fila con el estado de las variables
        cout << left 
             << setw(5)  << i
             << setw(8)  << digito
             << setw(10) << s
             << setw(16) << x
             << setw(12) << freq_previa
             << setw(12) << res
             << "d[" << x << "] = " << d[x] << "\n";
    }

    cout << string(80, '-') << "\n";
    cout << "RESULTADO FINAL (Subarrays buenos): " << res << "\n\n";
}

int main() {
    int t;
    cout << "Cantidad de casos de prueba: ";
    cin >> t;
    
    while (t--) {
        pruebaDeEscritorio();
    }

    return 0;
}