#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef vector<ll> vll;

const ll MOD = 676767677;
ll guas(ll n){return n*(n+1) /2;}



int main(){
        ios::sync_with_stdio(false);
    cin.tie(nullptr);

    ll t;cin>>t;
    while(t--){
        ll n;cin>>n;
        vll arr(n);for(auto &a:arr)cin>>a;
        ll mx = 0;
        vll indices(n + 5, 0);
        for (int i = 0; i < n; i++)
        {
            ll val =arr[i] -(arr[i]/2)-1;
            if(arr[i]< n+5)indices[arr[i]] = 1;
            if(val<0)continue;
            mx  = max(mx,val);
        }
        vll aux(mx + 5, 0);
        for (int i = min(mx-1,n+1); i >= 0; i--)
        {   
            aux[i] += aux[i+1];
        }
        
        ll res = 0;
        ll unos = 0;

        int j = 1;
        for (int i = 1; i <= n+10; i++,j++)
        {
            if(aux[i]>= aux[i-1])aux[i] = aux[i-1]-1;
            if(aux[i] == 0 || i == n){break;}
        }
        while(j<=n && indices[j]){
            j++;
        }
        cout<<j<<"\n";
    }   
    return 0;
}