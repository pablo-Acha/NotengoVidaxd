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
        ll n,m;cin>>n>>m;
        string s;cin>>s;
        vector<vll> arr(n,vll(m));
        for(auto &v:arr)for(auto &x:v)cin>>x;
        ll x = 0, y = 0;
        for (int i = 0; i < s.size(); i++)
        {
            if(s[i] == 'D'){
                ll sum = 0;
                for (int j = 0; j < m; j++)
                {
                    sum+= arr[y][j];
                }
                arr[y][x]= -sum;
                y++;
            }else{
                ll sum = 0;
                for (int j = 0; j < n; j++)
                {
                    sum+= arr[j][x];
                }
                arr[y][x]= -sum;
                x++;
            }
        }
        ll sum = 0;
        for (int i = 0; i < m; i++)
        {
            sum += arr[n-1][i];
        }
        arr[n-1][m-1] = -sum;
        for(auto &v:arr){{for(auto &x:v)cout<<x<<" ";}cout<<"\n";}
        
        
    }

    return 0;
}