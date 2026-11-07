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

    ll t;cin>>t;
    while(t--){
        ll n;cin>>n;
        vll arr(n);for(auto &a:arr)cin>>a;
        
        
        
        
        vll iz,der;
        vll pos;
        for (int i = 0; i < n; i++)
        {
            if(arr[i] !=-1){
                pos.push_back(i);
                iz.push_back(0);
                der.push_back(0);
            }
        }
        if(pos.size() == 0){
            for(int i = 0;i<n;i++)cout<<1;
            cout<<"\n";
            continue;
        }
        if(pos[0]>=arr[pos[0]]){iz[0] = 1;arr[pos[0]-arr[pos[0]]] = 0;}
        if(n-1-pos[pos.size()-1]>=arr[pos[pos.size()-1]]){der[pos.size()-1] = 1;  arr[pos[pos.size()-1]+arr[pos[pos.size()-1]]] = 0;}
        
        bool f= 1;
        ll m= pos.size();
        for (int i = 0; i < m-1; i++)
        {
            ll su = arr[pos[i]]+arr[pos[i+1]];
            ll d= abs(arr[pos[i]]-arr[pos[i+1]]);
            if(pos[i+1]-pos[i]>=su){
                der[i] = 1;
                iz[i+1] = 1;
                arr[pos[i]+arr[pos[i]]] = 0;
                arr[pos[i+1]-arr[pos[i+1]]] = 0;
            }else if(pos[i+1]-pos[i]<d){
                // cout<<pos[i]<<" "<<pos[i+1]<<" "<<d<<"\n";
                f = 0;
                break;
            }
        }
        if(!f){
            cout<<"-1\n";
            continue;
        }
        // cout<<"xxx\n";
        for (int i = 1; i < m; i++)
        {
            ll d= arr[pos[i]]-arr[pos[i-1]];
            if(!iz[i] && iz[i-1] && d == pos[i]-pos[i-1]){
                iz[i] = 1;
            }
        }
        // cout<<"xxx\n";
        // for(auto x:pos)cout<<x<<" ";cout<<"\n";
        // cout<<m<<"\n";
        for (int i = m-2; i >=0; i--)
        {
            // cout<<i<<"\n";
            ll d= arr[pos[i]]-arr[pos[i+1]];
            // cout<<i<<"\n";
            if(!der[i] && der[i+1] && d == pos[i+1]-pos[i]){
                der[i] = 1;
            }
        }
        // cout<<"xxx\n";

        for (int i = 0; i < m && f; i++)
        {
            if(!der[i] && !iz[i])f = 0;
        }
        // cout<<"xxx\n";

        if(!f){
            cout<<"-1\n";
            continue;
        }
        string s(n,'0');
        for (int i = 0; i < n; i++)
        {
            if(arr[i] == 0){
                s[i] = '1';
            }
        }
        cout<<s<<"\n";
        
    }

    return 0;
}