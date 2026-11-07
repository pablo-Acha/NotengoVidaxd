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
        string s;cin>>s;
        bool f = 1;
        bool sum = 1;
        ll res = 1;
        for (int i = 0; i < n; i+=2)
        {
            if(s[i] !='?'){
                sum = 0;
                char acc = s[i];
                for (int j = i+2; j < n; j+=2)
                {   
                    if(acc == '0' && s[j]== '0' || acc == '1' && s[j]== '1'){
                        f = 0;
                        break;
                    }else{
                        acc = acc == '0'?'1':'0';
                    }
                }
                acc = s[i];
                for (int j = i-2; j >=0; j-=2)
                {   
                    if(acc == '0' && s[j]== '0' || acc == '1' && s[j]== '1'){
                        f = 0;
                        break;
                    }else{
                        acc = acc == '0'?'1':'0';
                    }
                }
                break;
            }
        }
        if(sum)res*=2;
        sum = 1;
        for (int i = 1; i < n; i+=2)
        {
            if(s[i] !='?'){
                sum = 0;
                char acc = s[i];
                for (int j = i+2; j < n; j+=2)
                {   
                    if(acc == '0' && s[j]== '0' || acc == '1' && s[j]== '1'){
                        f = 0;
                        break;
                    }else{
                        acc = acc == '0'?'1':'0';
                    }
                }
                acc = s[i];
                for (int j = i-2; j >=0; j-=2)
                {   
                    if(acc == '0' && s[j]== '0' || acc == '1' && s[j]== '1'){
                        f = 0;
                        break;
                    }else{
                        acc = acc == '0'?'1':'0';
                    }
                }
                break;
            }
        }
        if(sum)res*=2;
        if(f){
            cout<<res<<"\n";
        }else{
            cout<<0<<"\n";
        }
    }

    return 0;
}