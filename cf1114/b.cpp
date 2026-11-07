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
        ll res = 0;
        for (int i =1; i < n-1; i++)
        {
            if(s[i-1] ==s[i+1] && s[i]!=s[i-1]){
                s[i] = s[i-1];
                f = 0;
                break;
            }
        }
        // cout<<s<<"\n";
        
        for (int i = 0; i < n;)
        {
            char aux = s[i];
            ll cnt = 0;
            while(i<n && aux == s[i]){
                cnt++;
                i++;
                // cout<<"x\n";
            }
            if(f && cnt == 1 && i-1>0 && i-1<n-1){
                f = 0;
            }else{
                res++;
            }
        }
        cout<<res<<"\n";
    
    }

    return 0;
}