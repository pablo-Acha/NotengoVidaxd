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
    while(t--)
    {
        ll n;cin>>n;
        vll arr(n);for(auto &a:arr)cin>>a;
        bool f = 1;
        vll brr,crr;
        for (int i = 0; i < n; i++)
        {
            if(arr[i]!=i+1){
                brr.push_back(i+1);
                crr.push_back(arr[i]);
            }
        }
        // for(auto x:brr)cout<<x<<" ";cout<<"\n";
        // for(auto x:crr)cout<<x<<" ";cout<<"\n";
        ll dif = n;
        for (int i = 0; i < brr.size(); i++)
        {
            if(i>0 &&crr[i]-crr[i-1] == 1){f = 0;break;}
            if(brr[i]!=crr[brr.size()-i-1]){
                f = 0;
                break;
            }
        }
        
        
        
        cout<<(f?"YES\n":"NO\n");
    }

    return 0;
}