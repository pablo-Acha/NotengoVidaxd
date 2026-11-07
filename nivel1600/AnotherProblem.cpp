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
        ll res = 0;
        for (int i = 0,aux; i < n; i++)
        {
            aux = 1;
            while(aux <=arr[i] && aux*arr[i]+i<n){
                if(arr[aux*arr[i]+i] == aux)res++;
                aux++;
            }
            aux = 1;
            while(aux <arr[i] && i-aux*arr[i]>=0){
                if(arr[i-aux*arr[i]] == aux)res++;
                aux++;
            }
        }
        cout<<res<<"\n";
        
    }

    return 0;
}