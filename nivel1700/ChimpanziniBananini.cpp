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
        ll q;cin>>q;
        deque<ll> arr,brr;
        ll sum = 0, mus = 0;
        ll acc = 0;
        bool f = 0;
        for (int i = 0; i < q; i++)
        {
            ll x;cin>>x;
            if(x == 1){
                if(f){
                    ll x = arr.back();
                    sum = sum -(x*arr.size())+acc;
                    mus = mus +(x*arr.size())-acc;
                    arr.pop_back();
                    arr.push_front(x);
                    brr.pop_front();
                    brr.push_back(x);
                }else{
                    ll x = brr.back();
                    mus = mus -(x*brr.size())+acc;
                    sum = sum +(x*brr.size())-acc;
                    brr.pop_back();
                    brr.push_front(x);
                    arr.pop_front();
                    arr.push_back(x);
                }
            }else if(x == 2){
                f = !f;
            }else{
                ll e;cin>>e;
                if(f){
                    arr.push_back(e);
                    brr.push_front(e);
                    sum += e*arr.size();
                    mus = mus +acc+e;
                }else{
                    brr.push_back(e);
                    arr.push_front(e);
                    mus += e*arr.size();
                    sum = sum +acc+e;
                }
                acc+= e;
            }
            cout<<(f?sum:mus)<<"\n";
        }
        
    }

    return 0;
}