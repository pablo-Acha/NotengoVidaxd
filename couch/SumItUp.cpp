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

    while (true)
    {
        ll t,n;cin>>t>>n;
        if(n == 0)break;
        vll arr(n);for(auto &a:arr)cin>>a;
        // reverse(all(arr));
        set<vll> sums;
        // for(auto x:arr){cout<<x<<" ";cout<<"\n";}
        for (int i = 0; i < (1<<n); i++)
        {
            ll aux = i;
            ll j = 0;
            vll acc;
            ll sum = 0;
            while(aux){
                if(aux&1){
                    acc.push_back(arr[j]);
                    sum+= arr[j];
                }
                j++;
                aux/=2;
            }
            if(sum == t){
                sums.insert(acc);
            }
        }
        cout<<"Sums of "<<t<<":\n";
        if(sums.size() == 0){
            cout<<"NONE\n";
        }else{
            vector<vll> res;
            for(auto v:sums){
                res.push_back(v);
            }
            for (int i = res.size() - 1; i >= 0; i--)
            {
                for (int j = 0; j < res[i].size(); j++)
                {
                    if(j)cout<<"+";
                    cout<<res[i][j];
                }
                cout<<"\n";
            }
        }
        
    }
    

    return 0;
}