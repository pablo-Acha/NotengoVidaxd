#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef vector<ll> vll;

ll pot2(ll pot){
    ll res = 1;
    for (int i = 0; i < pot; i++)
    {
        res*=2;
    }
    return res-1;
    
}

int main(){
    int t;cin>>t;
    while(t--){
        int n;cin>>n;
        vll res;
        set<ll> usados;
        int ibit = -1;
        ll aux = pot2(n);
        while(aux){
            aux = aux>>1;
            ibit++;
        }

        for (int i = ibit; i >=0; i--)
        {
            vll temp;
            ll ini = (1<<(i+1))-1;
            temp.push_back(ini);
            usados.insert(ini);
            for (int j = 0; j < 1<<(ibit-i); j++)
            {
                ll val = ini+(j<<(i+1));
                // cout<<j<<endl;
                // if(ini == 3)cout<<"----"<<val<<"---"<<endl;
                if(usados.find(val)!=usados.end())continue;
                temp.push_back(val);
                usados.insert(val);
            }
            sort(temp.begin(),temp.end());
            for(auto a:temp)cout<<a<<" ";
        }

        for (int i = 0; i < (1<<n); i++)
        {
            if(usados.find(i)!=usados.end())continue;
            cout<<i<<" ";
        }
        cout<<endl;        
    }
    return 0;
}