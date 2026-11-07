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

    ll n,k;cin>>n>>k;
    vll res;
    set<ll> arr;
    for (int i = 0; i < n; i++)
    {
        ll a;cin>>a;
        arr.insert(a);
    }
    for(auto x:arr)res.push_back(x);    
    ll ini = 0,fn = res.size();
    for (int i = 0; i < k-1; i++)
    {   set<ll> aux;
        // for(auto x:res){
        //     cout<<x<<" ";
        // }
        // cout<<"\n";
        for (auto x:arr)
        {
            for (int h = ini; h < fn; h++)
            {
                // cout<<res[h]<<" "<<x<<"\n";
                aux.insert(res[h]+x);
            }
        }
        // cout<<"------\n";
        for(auto x:aux){
            res.push_back(x);
        }
        ini = fn, fn = res.size();    
        // cout<<ini<<" "<<fn<<"\n";
    }
    for (int i = ini; i < fn; i++)
    {
        cout<<res[i]<<" ";
    }
    
    // for(auto a:res)cout<<a<<" ";
    cout<<"\n";

    return 0;
}