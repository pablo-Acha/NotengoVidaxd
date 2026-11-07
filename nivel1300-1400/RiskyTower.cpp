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
        vector<vll> arr(n,vll(m));
        vll v(n);for(auto &x:v)cin>>x;
        for(auto &v:arr)for(auto &x:v)cin>>x;
        priority_queue<ll> pq;
        ll res = m;
        for (int i = 1; i < n; i++)
        {
            v[i] = min(v[i],v[i-1]);
        }
        
        for (int i = n-1; i >=0; i--)
        {
            for (int j = 0; j < m; j++)
            {
                pq.push(arr[i][j]);
            }
            ll sum = 0;
            vll aux;
            ll cnt= 0;
            for (int j = 0; j < m; j++)
            {
                aux.push_back(pq.top());
                sum+= pq.top();
                cnt++;
                pq.pop();
                if(sum>=v[i])break;
            }
            for(auto x:aux)pq.push(x);
            res = min(res,cnt);
        }
        cout<<res<<"\n";
    }

    return 0;
}