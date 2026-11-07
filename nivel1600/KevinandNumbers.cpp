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
        multiset<ll> brr;
        for (int i = 0; i < m; i++)
        {
            ll a;cin>>a;
            brr.insert(a);
        }
        priority_queue<ll,vll, greater<ll>> pq;
        for (int i = 0; i < n; i++)
        {
            if(brr.find(arr[i])!= brr.end()){
                brr.erase(arr[i]);

            }else{
                pq.push(arr[i]);
            }
        }
        ll acc = 0;
        bool f = 1;
        while(!pq.empty()){
            if(acc == 0){
                acc = pq.top();
                pq.pop();
            }else{
                if(pq.top()-acc<=1)
                {
                    acc+= pq.top();
                    pq.pop();
                    if(brr.find(acc) != brr.end()){
                        brr.erase(acc);
                    }else{
                        pq.push(acc);
                    }
                    acc = 0;
                }else{
                    f = 0;
                    break;
                }
            }
        }
        cout<<(pq.empty() && acc == 0?"YES\n":"NO\n");

    }

    return 0;
}