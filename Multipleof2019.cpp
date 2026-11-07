#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef vector<ll> vll;
typedef  pair<int,int> pii;
typedef  pair<ll,ll> pll;
typedef  vector<int> vi;

#define all(x) (x).begin(), (x).end()


string resta(std::string a, std::string b) {
    // Si 'b' es mayor que 'a' numéricamente, la resta a - b daría un resultado negativo
    if (a.length() < b.length() || (a.length() == b.length() && a < b)) {
        return "-" + resta(b, a);
    }

    std::string resultado = "";
    int i = a.length() - 1;
    int j = b.length() - 1;
    int acarreo = 0;

    while (i >= 0) {
        int digitoA = a[i] - '0';
        int digitoB = (j >= 0) ? (b[j] - '0') : 0;

        int resta = digitoA - digitoB - acarreo;

        if (resta < 0) {
            resta += 10;
            acarreo = 1;
        } else {
            acarreo = 0;
        }

        resultado.push_back(resta + '0');
        i--;
        j--;
    }

    // Invertimos la cadena porque procesamos desde las unidades hasta las decenas/centenas
    std::reverse(resultado.begin(), resultado.end());

    // Eliminamos ceros a la izquierda (ejemplo: "005" -> "5")
    size_t primerNoCero = resultado.find_first_not_of('0');
    if (primerNoCero != std::string::npos) {
        return resultado.substr(primerNoCero);
    }

    return "0"; // Si todos los dígitos eran ceros (ejemplo: "10" - "10")
}
bool compararNumeros(const string& a, const string& b) {
    return stod(b) <= stod(a);
}
bool aumentar(string r){

    for (int i = 0; i < r.size(); i++)
    {
        if(r[i] !='0')return false;
    }
    return true;
}

int main() {
    // ios::sync_with_stdio(false);
    // cin.tie(nullptr);
    string s;cin>>s;
    // reverse(all(s));
    ll n = s.size();
    if(n<4){
        cout<<0<<"\n";
        return 0;
    }
    multiset<string> mts;
    vector<string> mul(10);
    for (int i = 0; i < 10; i++)
    {
        ll res = i*2019;
        string st = to_string(res);
        // reverse(all(st));
        mul[i] = st;
    }
    mul[0]= "0000";
    // for(auto x:mul)cout<<x<<" ";
    cout<<"\n";
    ll res = 0;
    for (int i = n-1; i >=0; i--)
    {
        multiset<string> nu;
        string aux ="0"; 
        if(i-3>=0){aux = s.substr(i-3,4);
        mts.insert(aux);}
        if(i-4>=0){aux = s.substr(i-4,5);
        mts.insert(aux);}

        for (int j = 0; j < 10; j++)
        {
            ll tam =mul[j].size(); 
            if(i-tam+1>=0){
                // cout<<j<<" "<<mul[j]<<" "<<aux<<"\n";
                // cout<<mts.size()<<"\n";
                for(auto x:mts){
                    ll tamx = x.size();
                    string aux = s.substr(i-tam+1,tam-tamx) + x; 
                    if(!compararNumeros(aux,mul[j]))continue;
                    // cout<<aux<<" "<<mul[j]<<"\n";
                    string r = resta(aux,mul[j]);
                    
                    if(r[r.size()-1] == 0){
                        nu.insert(r);
                        if(aumentar(r)){    
                            res++;
                        }
                    }
                }
            }
        }
        mts.clear();
        for(auto x:nu){
            string aux = x.substr(0,x.size()-1);
            mts.insert(x);
        }
    }
    cout<<res<<"\n";
    return 0;
}