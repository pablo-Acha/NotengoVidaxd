#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef vector<ll> vll;
typedef  pair<int,int> pii;
typedef  pair<ll,ll> pll;
typedef  vector<int> vi;

#define all(x) (x).begin(), (x).end()

vector<int> prefix_function(string &s) {
    int n = s.size();
    vector<int> pi(n, 0);
    
    for (int i = 1; i < n; i++) {
        int j = pi[i-1];
        
        while (j > 0 && s[i] != s[j]) {
            j = pi[j-1];
        }
        
        if (s[i] == s[j]) {
            j++;
        }
        
        pi[i] = j;
    }
    
    return pi;
}


int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    string s;cin>>s;
    int n = s.size();
    vector<int> pi = prefix_function(s);
    
    int mx = 0;
    
    for (int i = 0; i < n - 1; i++) {
        mx = max(mx, pi[i]);
    }
    
    int len = pi[n - 1];
    
    while (len > 0) {
    
        // ¿Qué condición indica que sirve?
        if (mx>=len) {
            cout << s.substr(0, len) << "\n";
            return 0;
        }
    
        // ¿Cómo pasas al siguiente borde?
        len = pi[len-1];
    }
    
    cout << "Just a legend\n";
    
    

    return 0;
}

