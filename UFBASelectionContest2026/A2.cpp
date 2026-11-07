#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef vector<ll> vll;
typedef  pair<int,int> pii;
typedef  pair<ll,ll> pll;
typedef  vector<int> vi;

#define all(x) (x).begin(), (x).end()


struct nodo
{
    ll valor;
    ll dist;
};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n; cin >> n;

    vll numeritos (n);

    for (ll i = 0; i < n; i++)
    {
        cin>>numeritos[i];
    }

    vector<nodo> dp (n+1,{0,0});

    ll distancia = 1;
    
    for (ll i = 1; i <= n; i++)
    {
        nodo mejorJ;

        for (ll j = i-1; j >= 0; j--)
        {
            mejorJ = {}

        }
         
    }
    
    
    return 0;
}