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
    while (t--)
    {
        ll n,a,b;cin>>n>>a>>b;
        vll arr(n);iota(all(arr),1LL);
        vll brr = arr;
        if(a == 0 && b == 0){
            cout<<"YES\n";
            for (int i = 1; i <= n; i++)
            {
                cout<<i<<" ";
            }
            cout<<"\n";
            for (int i = 1; i <= n; i++)
            {
                cout<<i<<" ";
            }
            cout<<"\n";
        }else if(a == 0 || b == 0 || a+b>n)
        {
            cout<<"NO\n";
        }else{
            cout<<"YES\n";
            ll x = min(a,b)-1;
            a-= x;
            b-= x;
            // cout<<a<<" "<<b<<"\n";
            vector<pll> res;
            for (int i = 0; i < x; i++)
            {
                res.push_back({brr.back(),arr[arr.size()-2]});
                brr.pop_back();
                arr.erase(arr.begin()+arr.size()-2);
                res.push_back({brr.back(),arr.back()});
                brr.pop_back();
                arr.pop_back();
            }
            ll y = max(a,b);

            for (int i = 0; i < y; i++)
            {
                if(b>a){
                    res.push_back({brr.back(),arr[arr.size()-2]});
                    brr.pop_back();
                    arr.erase(arr.begin()+arr.size()-2);
                }else{
                    res.push_back({brr[arr.size()-2],arr.back()});
                    arr.pop_back();
                    brr.erase(brr.begin()+brr.size()-2);
                }
            }
            while (!brr.empty())
            {
                res.push_back({brr.back(),arr.back()});
                brr.pop_back();                
                arr.pop_back();                
            }
            
            
            for (int i = 0; i < res.size(); i++)
            {
                cout<<res[i].second<<" ";
            }cout<<"\n";
            for (int i = 0; i < res.size(); i++)
            {
                cout<<res[i].first<<" ";
            }cout<<"\n";
        }
    }
    

    return 0;
}