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
        for (int i = 0; i < n; i++)
        {
            if(arr[i] == 1 || arr[i] == -1){
                if(arr[i] == -1)arr[i] = 1;
                break;
            }    
        }
        for (int i = n - 1; i >= 0; i--)
        {
            if(arr[i] == 1 || arr[i] == -1){
                if(arr[i] == -1)arr[i] = 1;
                break;
            }    
        }
        for (int i = 0; i < n; i++)
        {
            if(arr[i] == -1){
                arr[i] = 0;
            }
        }
        for(auto a:arr)cout<<a<<" ";cout<<"\n";
        
        
    }
    

    return 0;
}