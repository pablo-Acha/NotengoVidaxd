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
        ll n,k;cin>>n>>k;
        n*=2;
        string s;cin>>s;
        ll x = 0;
        ll o = 0;
        for (int i = 0; i < n; i++)
        {
            if(i&1){
                if(s[i] == '1' && s[(i+1+n)%n] =='0'){
                    o +=1;
                    // cout<<i<<" "<<((i+1+n)%n)<<" ";
                    // cout<<x<<" "<<o<<"\n";
                }else if(s[i] == '1' && s[(i+1+n)%n] =='1'){
                    x+=1;
                    // cout<<i<<" "<<((i+1+n)%n)<<" ";
                    
                    // cout<<x<<" "<<o<<"\n";
                }
            }else{
                if(s[i] == '1' && s[(i+1+n)%n] =='0'){
                    x +=1;
                    // cout<<i<<" "<<((i+1+n)%n)<<" ";
                    
                    // cout<<x<<" "<<o<<"\n";
                }else if(s[i] == '1' && s[(i+1+n)%n] =='1'){
                    o+=1;
                    // cout<<i<<" "<<((i+1+n)%n)<<" ";
                    // cout<<x<<" "<<o<<"\n";
                }
            }
        }
        cout<<x<<" "<<o<<"\n";
    }

    return 0;
}