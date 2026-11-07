#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef vector<ll> vll;

ll guas(ll n) { return n * (n + 1) / 2; }

const ll MOD = 998244353;
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    ll t;
    cin >> t;
    while (t--)
    {
        ll n;
        cin >> n;
        vll arr(n);
        for (auto &a : arr)
            cin >> a;
        for (int k = 0; k < n; k++)
        {
            vll brr(n);

            for (int i = (k + 1) % n; i!=(k + n)%n; i = (i + 1) % n)
            {
                brr[i] = max(arr[(i + n - 1) % n],brr[(i + n - 1) % n]);
            }
            // for (auto a : brr)
            //     cout << a << " ";
            // cout << "\n";
            ll ul=arr[(k+n- 1)%n];
            ll mx = 0;
            if(ul>=brr[(k+n-1)%n]){
                mx  = accumulate(brr.begin(),brr.end(),0LL);
            }else{
                
                brr[(k+n-1)%n] = ul;
                for (int i = (k + n - 2) % n;brr[i]>= ul && i!=k;i = (i + n - 1) % n)
                {
                    brr[i] = ul;
                    ul = max(ul,arr[i]);
                    if (i == k)break;
                }
                mx  = accumulate(brr.begin(),brr.end(),0LL);
            }
            // for(auto a:brr){
            //     cout<<a<<" ";
            // }
            // cout<<"\n";
            cout<<mx<<" ";

        }
        cout<<"\n";
    }
    return 0;
}