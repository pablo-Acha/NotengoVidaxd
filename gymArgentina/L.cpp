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
    ll indice;


    bool operator<( const nodo a) const{
        return valor<a.valor;
    }
};


int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    ll n,m;cin>>n>>m;
    set<ll> st;
    vll numeritos(n);

    set<nodo> noditos;
    set<nodo> noditosCopia;
    ll maxi = -10;
    for (ll i = 0; i < n; i++)
    {
        ll x ; cin>>x;
        maxi = max(maxi, x);
        numeritos[i] = x;
        st.insert(x);
        noditos.insert({x,i});
    }
    
    vll copia = numeritos; 
    
    reverse(copia.begin(), copia.end());

    for (ll i = 0; i < n; i++)
    {
        noditosCopia.insert({numeritos[i],i});
        
    }

    ll izq = 0;
    ll der = 0;

    ll lu = 0;

    while(izq != maxi && der != maxi){
        
        auto it = noditosCopia.begin();
        
        ll siguiente = *st.upper_bound(der); 

        while(it != noditosCopia.end()){
            siguiente = *st.upper_bound(der); 

            cout<<"siguiente: " << siguiente<<endl;


            it = noditosCopia.upper_bound({der,0});

            if(it == noditosCopia.end()) break;
            nodo actual = *it;

            cout<<der <<" "<<actual.valor<<" ddddddddddddddddd"<<endl;

            if(actual.valor != siguiente){
                break;
            }

            der = actual.valor;
        }
        it = noditos.begin();

        while(it != noditos.end()){
            
            siguiente = *st.upper_bound(izq); 
            
            if(it == noditos.end()) break;
            
            cout<<"siguiente: " << siguiente<<endl;

            it = noditos.upper_bound({izq,0});
            nodo actual = *it;

            cout<<izq <<" "<<actual.valor<<" llllllllllllll"<<endl;
            if(actual.valor != siguiente){
                break;
            }

            izq = actual.valor;
        }

        cout<<"izq " << izq <<" der "<< der<<endl;

        if(izq > der){

            der = izq;
        }else{

            izq = der;
        }
        lu++;

    }

    cout<<st.size() <<" "<< lu<<endl;
    
    









    return 0;
}