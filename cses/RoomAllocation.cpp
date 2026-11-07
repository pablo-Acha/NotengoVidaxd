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
    vector<tuple<ll,ll,ll>> arr;
    vll pos(t);
    for (int i = 0; i < t; i++)
    {
        ll a,b;cin>>a>>b;
        arr.push_back({a,b,i});
    }
    sort(all(arr));
    priority_queue<pll,vector<pll>, greater<pll>> pq;
    pq.push({1e18,0});
    ll act = 0;
    for (int i = 0; i <t; i++)
    {
        auto [a,b,ind] = arr[i];
        auto [last,room] = pq.top();
        if(last<a)
        {
            pos[ind] = room;
            pq.pop();
            pq.push({b,room});
        }else{
            act++;
            pos[ind] = act;
            pq.push({b,act}); 
        }
    }
    cout<<act<<"\n";
    for(auto x:pos){
        cout<<x<<" ";
    }
    cout<<"\n";
    return 0;
}