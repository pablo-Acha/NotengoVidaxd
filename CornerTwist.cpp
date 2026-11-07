#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef vector<ll> vll;
ll f(ll i, ll x){
    if(i<x){
        return i+3 - x;
    }else{
        return i-x;
    }
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    ll t;cin>>t;
    while(t--){
        ll n,m;cin>>n>>m;
        vector<string> lec(n);
        vector<vll> arr(n,vector<ll>(m));
        vector<vll> brr(n,vector<ll>(m));
        for (int i = 0; i < n; i++)cin>>lec[i];
        for (int i = 0; i < n; i++)for (int j = 0; j < m; j++)arr[i][j] = lec[i][j]-'0';
        for (int i = 0; i < n; i++)cin>>lec[i];
        for (int i = 0; i < n; i++)for (int j = 0; j < m; j++)brr[i][j] = lec[i][j]-'0';
        vector<vll> crr(n,vector<ll>(m));
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                crr[i][j] = f(brr[i][j],arr[i][j]);
            }   
        }
        // cout<<"aaa"<<endl;
        vll verH(m);
        vll verV(n);
        bool flag = 1;
        // for (int i = 0; i < n; i++)
        // {
        //     for (int j = 0; j < m; j++)
        //     {
        //         cout<<crr[i][j]<<" ";
        //     }   
        //     cout<<endl;
        // }
        for (int i = 0; i < n && flag; i++)
        {
            ll unos = 0,dos = 0;
            for (int j = 0; j < m; j++)
            {
                unos += crr[i][j] == 1;
                dos += crr[i][j] == 2;
            }
            ll mn = min(unos,dos), mx = max(unos,dos);
            mx = mx-mn;
            if(!mx || mx%3 == 0)continue;
            else flag = 0;
        }
        for (int i = 0; i < m && flag; i++)
        {
            ll unos = 0,dos = 0;
            for (int j = 0; j < n; j++)
            {
                unos += crr[j][i] == 1;
                dos += crr[j][i] == 2;
                
            }
            ll mn = min(unos,dos), mx = max(unos,dos);
            mx = mx-mn;
            if(!mx || mx%3 == 0)continue;
            else flag = 0;
        }
        cout<<(flag?"YES":"NO")<<"\n";
    }

    return 0;
}