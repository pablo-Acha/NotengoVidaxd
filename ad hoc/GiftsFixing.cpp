#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef vector<ll> vll;
int main(){

    int t;cin>>t;
    while (t--)
    {
        int n;cin>>n;
        vll arr(n),brr(n);
        for (int i = 0; i < n; i++)
        {
            cin>>arr[i];
        }
        for (int i = 0; i < n; i++)
        {
            cin>>brr[i];
        }
        ll a = *min_element(arr.begin(),arr.end()),b= *min_element(brr.begin(),brr.end());
        ll res = 0;
        for (int i = 0; i < n; i++)
        {
            res+= max(arr[i]-a,brr[i]-b);
        }
        cout<<res<<"\n";
    }
    
}
