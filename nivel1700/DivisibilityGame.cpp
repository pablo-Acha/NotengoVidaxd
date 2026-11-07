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
    while(t--)
    {
        ll n,m;cin>>n>>m;
        vll arr(n);for(auto &a:arr)cin>>a;
        vll brr(m);for(auto &a:brr)cin>>a;
        vll ver(n+m+1);
        for (int i = 0; i < n; i++)
        {
            ver[arr[i]]++;
        }
        
        
        for (int i = ver.size()-1; i >=1; i--)
        {
            if(ver[i]>0)for (int j = i*2; j < ver.size(); j+=i)
            {
                ver[j] += ver[i];
            }
        }
        ll a= 0,b = 0,c= 0;
        for (int i = 0; i < m; i++)
        {
            if(ver[brr[i]] == n){
                a++;
            }else if(ver[brr[i]] == 0){
                b++;
            }else{
                c++;
            }
        }
        // for(int i = 0;i<13;i++)cout<<ver[i]<<" ";cout<<"\n";
        a+= c&1;
        // cout<<a<<" "<<b<<" "<<c<<"\n";
        if(a<=b){
            cout<<"Bob\n";
        }else{
            cout<<"Alice\n";
        }
    }

    return 0;
}