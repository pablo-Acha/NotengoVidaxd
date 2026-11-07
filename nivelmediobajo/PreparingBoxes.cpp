#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef vector<ll> vll;
const ll MOD = 1e9+7;

ll gaus(ll n){
    return (n*(n+1))/2;
}


int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    ll n;cin>>n;
    vll arr(n+1);
    for (int i = 1; i < n+1; i++)
    {
        cin>>arr[i];
    }
    vll ayuda(n+1);
    vll res;
    bool f = 1;
    for (int i = n; i > 0; i--)
    {
        if(i+i>=n+1){
            if(arr[i]){
                ayuda[i]++;
                res.push_back(i);
            }
        }else{
            if((ayuda[i+i]+1)%2 == arr[i]){
                res.push_back(i);
                ayuda[i] = ayuda[i+i]+1;
            }else if(ayuda[i+i]%2 == arr[i]){
                ayuda[i] = ayuda[i+i];
            }else{
                f = 0;
                break;
            }
        }    
    }

    if(!f){
        cout<<-1<<"\n";

    }else{
        cout<<res.size()<<"\n";
        for (int i = 0; i < res.size(); i++)
        {
            cout<<res[i]<<" ";
        }
        cout<<"\n";

    }
        
    return 0;
}