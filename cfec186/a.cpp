#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef vector<ll> vll;

int main(){
    int t;cin>>t;
    while(t--){
        int n;cin>>n;
        string s;cin>>s;
        ll res = 0;
        ll nuevo = 0;
        
        for (int i = 0; i <= n-4; i++)
        {
            
            
            res+= s.substr(i,4) == "2025";
            nuevo+= s.substr(i,4) == "2026";
        }
        if(nuevo>0 || res == 0){
            cout<<0<<endl;
        }else{
            cout<<1<<endl;
        }
        
    }
}