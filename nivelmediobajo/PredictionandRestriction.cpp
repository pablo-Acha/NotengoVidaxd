#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef vector<ll> vll;
const ll MOD = 1e9+7;
vll primos;
vll aux(1e6+10,1);
void init(){
    aux[0] = 0;
    aux[0] = 0;
    for (int i = 2; i < 1e6+10; i++)
    {
        if(aux[i] == 0)continue;
        primos.push_back(i);
        for (int j = i*2; j < 1e6+10; j+=i)
        {
            aux[j] = 0;
        }
    }
    
}
ll r,p,s;
ll f(char t){
    ll res = 0;
    if(t == 'p'){
        res+= s; 
    }else if(t == 'r'){
        res+= p; 
    }else{
        res+= r; 
    }
    return res;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    ll n,k;cin>>n>>k;
    cin>>r>>s>>p;
    string t;cin>>t;
    vll arr(n);
    ll res = 0;
    for (int i = 0; i < k; i++)
    {
        arr[i] = 1;
        res+= f(t[i]);
    }
    // cout<<res<<"\n";
    for (int i = k; i < n; i++)
    {
        if(arr[i-k] && t[i] == t[i-k])continue;
        arr[i] = 1;
        res+= f(t[i]);
    }
    cout<<res<<"\n";
    return 0;
}