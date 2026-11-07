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

    ll n,k;cin>>n>>k;
    string s;cin>>s;
    s= '0'+s;
    n++;
    ll q;cin>>q;
    vll help(k,n);
    vll crr(k,1);
    vector<vll> arr(n);
    vll brr(n,0);
 

    
    for (ll i = n-1; i >= 0; i--)
    {
        ll mn = 1e18;
        for (int j = 0; j < crr.size(); j++)
        {
            mn = min(mn,crr[j]);
            // cout<<crr[j]<<" ";
        }
        // cout<<"\n";
        brr[i] = mn;
        arr[i] = help;
        if(i == 0)continue;
        help[s[i]-'a'] = i;
        crr[s[i]-'a'] = mn+1;
    }
    
    // for(auto x:brr)cout<<x<<" ";cout<<"\n";
    for (int i = 0; i < q; i++)
    {
        string c;cin>>c;       
        ll act = 0;
        ll j = 0;
        ll m = c.size();
        while(act<n && j<m){
            act = arr[act][c[j]-'a'];
            j++;
        }
        // cout<<act<<"\n";
        if(act == n)cout<<"0\n";
        else{
            cout<<brr[act]<<"\n";
        }
    }
    

    return 0;
}