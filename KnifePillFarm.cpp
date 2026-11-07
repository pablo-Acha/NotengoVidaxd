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
        ll n,m;cin>>n>>m;
        vll arr(n);for(auto &a:arr)cin>>a;
        priority_queue<ll> pq;
        vll res(n);
        ll sum = 0;
        for (ll i = 0; i < n; i++)
        {
            if(pq.size() == m-1){
                res[i] = sum+(arr[i]*m);
                if(!pq.empty() && pq.top()>arr[i]){
                    sum =sum+pq.top()-arr[i];
                    pq.pop();
                    pq.push(arr[i]);
                } 
            }else{
                sum -= arr[i];
                pq.push(arr[i]);
            }
        }
        // for(auto x:res)cout<<x<<" ";cout<<"\n";
        
        ll mx = *max_element(res.begin()+m-1,res.end());
        cout<<mx<<"\n";
    }

    return 0;
}