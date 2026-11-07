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
        string s;cin>>s;
        if(s[0] == '1'){
            ll cnt = 0;
            for (int i = 0; i < n; i++)
            {
                cnt+= s[i] == '0';
            }
            cout<<cnt<<"\n";
        }else{
            vll arr(n);
            arr[n-1] = s[n-1] == '0';
            for (int i = n - 2; i >= 0; i--)
            {
                arr[i] = arr[i+1]+(s[i] == '0');
            }
            ll cnt = 0;
            ll res = 0;
            // for(auto x:arr)cout<<x<<" ";cout<<"\n";
            for (int i = 1; i < n; i++)
            {
                if(s[i] == '1'){

                    if(cnt>=arr[i]){

                        break;
                    }
                    cnt++;
                    res++;
                }else{
                    if(cnt>=1)cnt--;
                }
            }   
            cout<<res<<"\n";
        }
    }
    

    return 0;
}