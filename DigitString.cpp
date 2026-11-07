#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef vector<ll> vll;

int main(){
    ll t;cin>>t;
    while(t--){
        string c;cin>>c;
        int n= c.size();
        ll res = 0;
        string s;
        for (int i = 0; i < n; i++)
        {
            if(c[i] == '4'){res++;continue;}
            s.push_back(c[i]);
        }
        int i = 0;
        n = s.size();
        ll a = 0,b = 0;
        while(i<n){
            while(i<n && s[i]!='2'){
                a++;
                i++;
            }
            while (i<n && s[i]=='2')
            {
                b++;
                i++;
            }
            if(a<=b){
                res +=a;
                b = 0,a = 0;
            }
        }
        res+= min(a,b);
        cout<<res<<"\n";
    }    
    return 0;
}