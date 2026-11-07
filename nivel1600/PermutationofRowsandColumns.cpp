#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef vector<ll> vll;
typedef  pair<int,int> pii;
typedef  pair<ll,ll> pll;
typedef  vector<int> vi;

#define all(x) (x).begin(), (x).end()

vector<vll> fun(vector<vll> arr){
    ll n= arr.size();
    ll m= arr[0].size();
    ll ind = 0;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if(arr[i][j] == 1){ind = j;break;}
        }
    }
    for (int i = 0; i < n; i++)
    {
        ll aux = arr[i][ind];
        arr[i].erase(arr[i].begin()+ind);
        vll temp;temp.push_back(aux);
        for(auto x:arr[i])temp.push_back(x); 
        arr[i] = temp;       
    }
    sort(all(arr));
    // for(auto v:arr){for(auto x:v)cout<<x<<" ";cout<<"\n";}
    vector<vll> brr(m);
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            brr[j].push_back(arr[i][j]);
        }
    }
    sort(all(brr));
    return brr;
    
}


int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    ll t;cin>>t;
    while(t--){
        ll n,m;cin>>n>>m;
        vector<vll> arr(n,vll(m));for(auto &v:arr)for(auto &x:v)cin>>x; 
        vector<vll> brr(n,vll(m));for(auto &v:brr)for(auto &x:v)cin>>x;
        vector<vll> crr = fun(arr);
        vector<vll> drr = fun(brr);
        cout<<(crr == drr?"YES\n":"NO\n");
        
    }

    return 0;
}