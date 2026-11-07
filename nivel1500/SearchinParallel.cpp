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
        ll n,a,b;cin>>n>>a>>b;
        priority_queue<pll> pq;
        for (int i = 0; i < n; i++)
        {
            ll x;cin>>x;
            pq.push({x,i});
        }
        ll aa = 1,bb = 1;
        vll arr,brr;
        for (int i = 0; i < n; i++)
        {
            auto [x,in]= pq.top();
            if(aa*a<bb*b){
                arr.push_back(in+1);
                aa++;
            }else{
                bb++;
                brr.push_back(in+1);
            }
            pq.pop();
        }
        cout<<arr.size()<<" ";for(auto a:arr)cout<<a<<" ";cout<<"\n";
        cout<<brr.size()<<" ";for(auto a:brr)cout<<a<<" ";cout<<"\n";

    }

    return 0;
}