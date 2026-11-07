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
        ll n,q;cin>>n>>q;
        vll arr(n+1),brr(n+1),bas;
        string s;cin>>s;
        for (int i = 0; i < n; i++)arr[i+1]= s[i]-'0';
        cin>>s;
        for (int i = 0; i < n; i++)brr[i+1] = s[i]-'0';
        vll ba(n+1),ca(n+1);

        for (int i = 1; i <= n; i++)
        {
            ba[i] = ba[i-1];
            ca[i] = ca[i-1];
            if(arr[i] == 1 && brr[i] == 0){
                ba[i]+= 1;
            }else if(arr[i] == 0 && brr[i] == 1){
                ca[i]+= 1;
            }
        }
        
        for (int i = 0; i < q; i++)
        {
            ll l,r;cin>>l>>r;
            ll b1 = ba[r]-ba[l-1],b2 = ca[r]-ca[l-1];
            ll sum = b1+b2;
            ll dif = abs(b1-b2);
            // if(min(b1,b2)>0)dif = max(dif-1,0LL);
            // cout<<dif<<"\n";
            if(dif<=(r-l+1-sum)){
                cout<<"YES\n";
            }else{
                cout<<"NO\n";
            }
        }
        
        
    }

    return 0;
}