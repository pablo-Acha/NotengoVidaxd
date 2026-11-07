#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef vector<ll> vll;



ll guas(ll n){return n*(n+1) /2;}
int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    ll t;cin>>t;
    while(t--){
        ll n;cin>>n;
        ll mxx = 0;
        vll arr(n);for(auto &a:arr){cin>>a;mxx = max(a,mxx);}
        deque<pair<ll,ll>> unicos;
        ll mn = 1e9;
        for (int i = n - 1; i >= 0; i--)
        {
            if(arr[i]<mn){
                unicos.emplace_front(arr[i],i);
                mn = arr[i];
            }
        }
        vll dist(unicos.size()),acc(unicos.size());
        dist[0] = unicos[0].second;
        for (int i = 1; i < unicos.size(); i++)
        {
            dist[i] = unicos[i].second -unicos[i-1].second;
        }
        acc[0] = unicos[0].first *(dist[0]+1);
        ll total = acc[0];
        for (int i = 1; i < unicos.size(); i++)
        {
            acc[i] = unicos[i].first *dist[i];
            total += acc[i];
        }
        // for(auto a:acc){
        //     cout<<a<<" ";
        // }
        // cout<<"\n";
        ll sum = accumulate(arr.begin(),arr.end(),0LL);
        // cout<<sum<<"\n";
        
        
        ll res = 0;
        
        for (int i = 0; i < dist.size(); i++)
        {

            ll aux = sum - (total) + (dist[i]-(i != 0));
            // cout<<i<<"  "<<sum<<" "<<total<<" "<<aux<<"\n";
            res =max(res, aux);
        }
        cout<<res<<"\n";
    }
       
    return 0;
}