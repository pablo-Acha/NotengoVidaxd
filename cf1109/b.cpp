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
        ll aux = 0;
        bool f = 1;
        for (int i = 0,j = 1; i < n; i++,j++)
        {
           arr[i] += aux;     
           if(arr[i]>=j){
            aux = arr[i]-j;
            arr[i] = j;
           }else{
            f = 0;
            break;
           }
        }
        if(f){
            cout<<"YES\n";
        }else{
            cout<<"NO\n";
        }
        
        
    }

    return 0;
}