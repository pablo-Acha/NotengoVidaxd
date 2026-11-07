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

    ll n;cin>>n;
    vll arr(n);for(auto &a:arr)cin>>a;
    vll brr = arr;
    sort(all(brr));
    ll l = -1,r = -1;
    for (int i = 0; i < n; i++)
    {
        if(arr[i]!=brr[i]){
            l = i;
            break;
        }
    }
    for (int i = n - 1; i >= 0; i--)
    {
        if(arr[i]!=brr[i]){
            r = i;
            break;
        }
    }
    if(l!=-1)reverse(arr.begin()+l,arr.begin()+r+1);
    bool f= is_sorted(all(arr));
    cout<<(f?"yes\n":"no\n");
    if(f && l!=-1)cout<<l+1<<" "<<r+1<<"\n";
    if(f && l ==-1)cout<<1<<" "<<1<<"\n";

    return 0;
}