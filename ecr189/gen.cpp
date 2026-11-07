#include <bits/stdc++.h>
using namespace std;

string random_string(int n) {
    string s;
    for (int i = 0; i < n; i++) {
        s += (rand() % 2 ? 'R' : 'B');
    }
    return s;
}

string same_color(int n) {
    char c = (rand() % 2 ? 'R' : 'B');
    return string(n, c);
}

pair<string,string> tricky_case(int n) {
    string a, b;

    int type = rand() % 3;

    if (type == 0) {
        // completamente random
        a = random_string(n);
        b = random_string(n);
    }
    else if (type == 1) {
        // columnas iguales (caso fácil)
        a = random_string(n);
        b = a;
    }
    else {
        // alternancia tipo ajedrez (caso tricky)
        for (int i = 0; i < n; i++) {
            if (i % 2 == 0) {
                a += 'R';
                b += 'B';
            } else {
                a += 'B';
                b += 'R';
            }
        }
    }

    return {a, b};
}

int main() {
    srand(time(0));

    int t = 10000;
    cout << t << "\n";

    int total_n = 0;

    for (int i = 0; i < t; i++) {
        int remaining = 200000 - total_n;
        if (remaining <= 0) break;

        int n = rand() % min(100, remaining) + 1;
        total_n += n;

        cout << n << "\n";

        auto [a, b] = tricky_case(n);

        cout << a << "\n";
        cout << b << "\n";
    }

    return 0;
}