#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef vector<ll> vll;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    ll t;cin>>t;
    while (t--) {
        ll n;cin>>n;
        string s;cin>>s;
        string c;
        for (int i = 0; i < n; )
        {
            if(s[i] == '0'){
                while(i<n && s[i] == '0'){
                    i++;
                }
                c.push_back('0');
            }else{
                while(i<n && s[i] == '1'){
                    i++;
                }
                c.push_back('1');
            }
        }

        if(c.size() == 2){
            cout<<"2\n";
        }else{{
            cout<<"1\n";
        }}
        
    }
}