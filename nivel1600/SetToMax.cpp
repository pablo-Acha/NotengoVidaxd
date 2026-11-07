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
        vll brr(n);for(auto &a:brr)cin>>a;
        priority_queue<pll, vector<pll>, greater<pll>> pq;
        for (int i = 0; i < n; i++)
        {
            pq.push({arr[i],i});
        }
        while(!pq.empty()){
            auto [x,ind] = pq.top();
            pq.pop();
            for (int i = ind+1; i < n; i++)
            {
                if(arr[i]<x && brr[i]>=x){
                    arr[i] = x;
                }else{
                    break;
                }
            }
            for (int i = ind - 1; i >= 0; i--)
            {
                if(arr[i]<x && brr[i]>=x){
                    arr[i] = x;
                }else{
                    break;
                }
            }
        }
        // for(auto x:arr)cout<<x<<" ";cout<<"\n";
        cout<<(arr== brr?"YES\n":"NO\n");
    }

    return 0;
}