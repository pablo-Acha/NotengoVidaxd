#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef vector<ll> vll;
typedef  pair<int,int> pii;
typedef  pair<ll,ll> pll;
typedef  vector<int> vi;

#define all(x) (x).begin(), (x).end()


bool f(multiset<ll> arr, multiset<ll> brr, ll mid){
    while(true){   
        ll a = *arr.begin();
        ll b = *brr.begin();
        if(a<b){
            auto p = brr.lower_bound(a+mid);
            if(p == brr.end())return false;
            arr.erase(arr.begin());
            brr.erase(p);
        }else{
            auto p = arr.lower_bound(b+mid);
            if(p == arr.end())return false;
            brr.erase(brr.begin());
            arr.erase(p);
        }
        if(arr.empty())break;
    }
    return true;
}


int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    ll t;cin>> t;
    while(t--){
        ll n;cin>>n;
        multiset<ll> mtl;
        for (int i = 0; i < n; i++)
        {
            ll a;cin>>a;

            mtl.insert(a);

        }
        multiset<ll> brr;
        for(int i = 0; i <n ; i++){ll a;cin>>a;brr.insert(a);}

        ll l = 0, r = 1e10, mid = 0;
        while (l<=r)
        {
            mid = (l+r)/2;
            if(f(mtl,brr,mid)){
                l = mid+1; 
            }else{
                r = mid-1;
            }
        }
        cout<<r<<"\n";
    }

    return 0;
}