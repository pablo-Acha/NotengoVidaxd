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
        ll n,k;cin>>n>>k;
        ll mx = 0;
        vll rand;
        vll temp(n+1);
        ll act = 0;
        vll arr(n);for(auto &a:arr)cin>>a;
        for (int i = 0; i < n; i++)
        {
            temp[arr[i]]++;
            while(temp[act] == 1){
                act++;
            }
            rand.push_back(act);
        }
        sort(all(rand),greater<ll>());
        mx = rand[k-1];
        pll par;
        for (int i = 0; i < n; i++)
        {
            for (int j = i+1; j < n; j++)
            {
                swap(arr[i],arr[j]);
                ll mex = 0;
                vll M(n+1);
                vll res;
                for (int h = 0; h < n; h++)
                {
                    M[arr[h]]++;
                    while(M[mex] == 1){
                        mex++;
                    }
                    res.push_back(mex);
                }
                sort(all(res),greater<ll>());
                if(res[k-1]>mx){
                    par = {i,j};
                    mx = res[k-1];
                }
                swap(arr[i],arr[j]);
            }
        }
        if(mx == rand[k-1]){
            cout<<"-1\n";
        }else{
            cout<<par.first+1<<" "<<par.second+1<<"\n";
        }
        
    }

    return 0;
}