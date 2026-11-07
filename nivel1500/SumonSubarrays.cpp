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
        ll n,k;cin>>n>>k;
        ll mx = (n*(n+1))/2;
        ll q = mx-k;
        vll res(n+1,1);
        ll top = n;
        // cout<<top<<"\n";

        while(q>top)
        {
            q-= top;
        // cout<<top<<"\n";

            res[top] = -1;
            top--;
        }
        // cout<<top<<"\n";
        res[q] = -1;
        ll sum = 1;
        ll antsum = -1;
        for (int i = 1; i <= n; i++)
        {
            if(res[i]>0){
                sum+= res[i]*antsum*-1;
                cout<<res[i]*antsum*-1<<" ";
            }else{
                antsum+= (res[i]*sum)-1;
                cout<<(res[i]*sum)-1<<" ";
            }
        }
        cout<<"\n";
        
    }
    

    return 0;
}