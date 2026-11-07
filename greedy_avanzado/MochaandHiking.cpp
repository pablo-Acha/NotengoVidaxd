#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef vector<ll> vll;

ll gaus(ll n){return n*(n+1) /2;}

bool f(ll mid,multimap<ll,vll> &mp){

    for(auto [a,v]:mp){
        for(auto x:v){
            if(mid<=x)return false;
            else mid++;
            
        }
    }
    return true;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    ll t;cin>>t;
    while(t--){
        ll n;cin>>n;
        vll arr(n+1);
        arr[0] = 0;
        for (int i = 1; i <= n; i++)
        {
            cin>>arr[i];
        }
        
        if(arr[n] == 0){
            for (int i = 1; i <= n+1; i++)
            {
                cout<<i<<" ";
            }
            cout<<"\n";
        }else{
            bool f = 0;
            int h = -1;
            for (int i = 1; i <= n &&!f; i++)
            {
                if(arr[i-1]== 0 && arr[i] == 1){
                    h = i;
                    f = 1;
                }
            }
            if(f){
                for (int i = 1; i <= n; i++)
                {
                    if(i == h){
                        cout<<n+1<<" ";
                    }
                    cout<<i<<" ";
                }
                cout<<"\n";
            }else{
                cout<<"-1\n";
            }
        }

        
    }

    return 0;
}