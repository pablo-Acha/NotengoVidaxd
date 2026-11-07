#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef vector<ll> vll;
typedef  pair<int,int> pii;
typedef  pair<ll,ll> pll;
typedef  vector<int> vi;

#define all(x) (x).begin(), (x).end()

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    ll n;cin>>n;
    vll arr(n);for(auto &x:arr)cin>>x;
    string s;cin>>s;
    ll temp = 1;
    vll ind(n);
    ind[0] = temp;
    for (int i = 0; i < n-1; i++)
    {
        if(s[i] == '='){
            ind[i+1] = temp;
        }else{
            temp++;
            ind[i+1] = temp;
        }
    }
    vector<vll> grafo(temp+1);
    vll grado(temp+1), val(temp+1);
    for (int i = 0; i < n-1; i++)
    {
        if(s[i]!='='){
            if(s[i] == '<'){
                grafo[ind[i]].push_back(ind[i+1]);
                grado[ind[i+1]]++;
            }else{
                grafo[ind[i+1]].push_back(ind[i]);
                grado[ind[i]]++;
            }
        }
    }
    queue<ll> qu;
    vll act(temp+1);
    for (int i = 1; i <= temp; i++)
    {
        if(grado[i] == 0){
            qu.push(i);
            act[i] = 1;
        }
    }
    while (!qu.empty())
    {
        auto nodo =qu.front();
        qu.pop();
        for(auto ni:grafo[nodo]){
            grado[ni]--;
            if(grado[ni] == 0){
                act[ni] = act[nodo]+1;
                qu.push(ni);
            }
        }
    }
    vll res(n);
    ll sum = 0;
    for (int i = 0; i < n; i++)
    {
        res[i] = act[ind[i]];
        sum += res[i]*arr[i];
    }
    cout<<sum<<"\n";
    for(auto x:res)cout<<x<<" ";cout<<"\n";
    
    return 0;
}