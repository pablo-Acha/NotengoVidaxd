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
        ll n;cin>>n;
        vll arr(n);for(auto &a:arr)cin>>a;
        vll time(n);
        ll op = 0;
        ll acc = 0;
        for (int i = n - 1; i >= 1; i--)
        {
            if(arr[i]<arr[i-1]){
                acc-= arr[i-1]-arr[i];
                time[i] = arr[i-1]-arr[i];
            }
        }
        op+= abs(acc);
        for (int i = 0; i < n; i++)
        {
            acc+= time[i];
            arr[i]+=acc;
            time[i] = 0;
        }
        
        for (int i = 0; i < n-1; i++)
        {
            if(arr[i]<arr[i+1]){
                acc-= arr[i+1]-arr[i];
                time[i] = arr[i+1]-arr[i];
            }
        }
        op+= abs(acc);
        for (int i = n - 1; i >= 0; i--)
        {
            acc+= time[i];
            arr[i]+=acc;
        }
        op+= abs(arr[0]);
        cout<<op<<"\n";
    }
    

    return 0;
}