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
        stack<ll> brr,crr;
        brr.push(0);crr.push(0);
        ll res = 0;
        for (int i = n - 1; i >= 0; i--)
        {
            if(brr.top()<= arr[i] && crr.top()<=arr[i]){
                if(crr.top()<=brr.top()){
                    brr.push(arr[i]);
                }else{
                    crr.push(arr[i]);
                }
            }else if(brr.top()<=arr[i]){
                brr.push(arr[i]);
            }else if(crr.top()<=arr[i]){
                crr.push(arr[i]);
            }else{
                if(crr.top()<=brr.top()){
                    brr.push(arr[i]);
                }else{
                    crr.push(arr[i]);
                }
                res++;
            }
        }
        cout<<res<<"\n";
    }

    return 0;
}