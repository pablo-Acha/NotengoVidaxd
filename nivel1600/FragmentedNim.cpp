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
        vll arr(n);for(auto &a:arr)cin>>a;
        sort(all(arr));
        bool a = 1;
        for (int i = 0; i < n; i++)
        {
            if(arr[i] ==1){
                a = !a;
            }else {
                break;
            }
        }
        if(arr[n-1] == 1){
            cout<<(!a?"Alice":"Bob")<<"\n";
        }else{
            cout<<(a?"Alice":"Bob")<<"\n";
        }
    }

    return 0;
}