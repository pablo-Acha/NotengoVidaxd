#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef vector<ll> vll;
ll f(vll &arr,vll &brr){
    multiset<ll> mls;
    for (int i = 0; i < brr.size(); i++)
    {
        mls.insert(brr[i]);
    }
    ll cnt = 0;
    // for(auto a:mls)cout<<a<<" ";
    for (int i = 0; i < arr.size(); i++)
    {
        for (int j = arr[i]-1; j < arr[i]-1+3; j++)
        {
            if(mls.size()<=0)break;
            if(mls.find(j)!=mls.end()){
                cnt++;
                mls.erase(mls.find(j));
                break;
            }
        }
        
    }
    return cnt;    
}
int main(){
    int n;cin>>n;
    vll arr(n);for(auto &a:arr)cin>>a;
    int m;cin>>m;
    vll brr(m);for(auto &a:brr)cin>>a;
    ll res = max(f(arr,brr),f(brr,arr));
    // ll res = f(brr,arr);
    cout<<res<<"\n";
    
    return 0;
}