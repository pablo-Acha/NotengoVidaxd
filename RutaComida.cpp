#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int main(){
    ll t;cin>>t;
    vector<ll> arr(t);for(auto &a:arr)cin>>a;
    ll n = arr.size();
    ll sum = accumulate(arr.begin(),arr.end(),0LL);
    ll part = sum/4;
    ll acc = 0;
    vector<ll> accs;
    for (int i = 0; i < n; i++)
    {
        acc+=arr[i];
        if(acc>=part){
            accs.push_back(acc);
            acc = 0;
        }
    }
    if(acc!=0)accs.push_back(acc);
    if(accs.size()>4)accs[3]+=accs[4];
    // sort(accs.begin(),accs.begin()+3);
    // cout<<accs[3]-accs[0]<<"\n";
    return 0;
}