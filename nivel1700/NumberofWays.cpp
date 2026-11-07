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
    vll arr(n+1);
    ll sum = 0;
    for (int i = 0; i < n; i++)
    {
        cin>>arr[i+1];
        sum+= arr[i+1];
    }
    if(sum%3 == 0){
        vll pre(n+1);
        for (int i = 1; i <= n; i++)
        {
            pre[i] += arr[i] +pre[i-1];
        }
        ll a = sum/3;
        ll aa = 2*a;
        vll sufa(n+1);
        vll sufaa(n+1);
        // for (int i = n ; i >= 1; i--)
        // {
        //     sufa[i] = (pre[i] == a) +(i<n? sufa[i+1]:0);
        // }
        for (int i = n-1 ; i >= 1; i--)
        {
            sufaa[i] = (pre[i] == aa) +(i<n? sufaa[i+1]:0);
        }
        ll res =0;
            // for(auto x:sufaa)cout<<x<<" ";
            // cout<<"\n";
            // for(auto x:pre)cout<<x<<" ";
            // cout<<"\n";
        for (int i = 1; i <= n-1; i++)
        {
            if(pre[i]== a && sufaa[i+1]>0){
                res += sufaa[i+1];
            }
        }
        cout<<res<<"\n";
    }else{
        cout<<"0\n";
    }
    

    return 0;
}