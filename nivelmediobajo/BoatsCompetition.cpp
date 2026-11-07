#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef vector<ll> vll;
// #include <iomanip>

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    ll t;cin>>t;
    while (t--)
    {
        int n;cin>>n;
        vll arr(n);
        for (int i = 0; i <n; i++)
        {
            cin>>arr[i];
        }
        sort(arr.begin(),arr.end());
        vector<set<ll>> sums(arr[n-1]+arr[n-1]+1);
        for (int i = 0; i < n; i++)
        {
            for (int j = i+1; j <n; j++)
            {
                ll aux =arr[i]+arr[j]; 
                if(sums[aux].find(i) == sums[aux].end() &&
                    sums[aux].find(j) == sums[aux].end()){
                    sums[aux].insert(i);
                    sums[aux].insert(j);
                }
            }
        }
        ll res = 0;
        for (int i = 0; i < sums.size(); i++)
        {
            ll aux = (sums[i].size()*1LL)/2LL;
            res =max(res,aux);
        }
        
        cout<<res<<"\n";
    }
    
    return 0;
}