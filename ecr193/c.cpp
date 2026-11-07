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
        ll n,m,x,y;cin>>n>>m>>x>>y;
        map<ll,ll> mp;
        priority_queue<ll> rep;
        vll arr(x);for(auto &a:arr){cin>>a;mp[a]++;}        
        vll brr(y);for(auto &a:brr){cin>>a;mp[a]++;if(mp[a] == 2)rep.push(a);}
        sort(all(brr),greater<ll>());
        sort(all(arr),greater<ll>());
        priority_queue<ll,vll,greater<ll>> pa,pb;
        for (int i = 0; i < x; i++)
        {
            if(mp[arr[i]] == 1)pa.push(arr[i]);         
            // cout<<pa.top()<<" ";
            if(pa.size() == n)break;
        }
        // cout<<"\n";
        while (pa.size()<n)pa.push(0);
        for (int i = 0; i < y; i++)
        {
            if(mp[brr[i]] == 1)pb.push(brr[i]);
            // cout<<pb.top()<<" ";
            if(pb.size() == m)break;
        }   
        // cout<<"\n";
        while (pb.size()<m)pb.push(0);

        while(!rep.empty()){
            if(rep.top()<pa.top() && rep.top()<pb.top())break;
            if(pa.top()<pb.top()){
                pa.pop();
                pa.push(rep.top());
            }else{
                pb.pop();
                pb.push(rep.top());
            }
            rep.pop();
        }
        ll res = 0;
        ll mn = min(pb.top(),pa.top());
        while(!pb.empty()){res+=pb.top();pb.pop();}
        // cout<<"\n";
        while(!pa.empty()){res+=pa.top();pa.pop();}
        // cout<<"\n";
        res-=mn;
        cout<<res<<"\n";

    }

    return 0;
}