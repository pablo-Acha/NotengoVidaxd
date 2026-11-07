#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef vector<ll> vll;

int main(){
    ll n;cin>>n;
    map<ll,ll> mp;
    bool f = 1;
    vll arr(n);for(auto &a:arr)cin>>a;
    for (int i = 0; i < n; i++)
    {
        if(arr[i] == 25){
            mp[25]++;
        }else if(arr[i] == 50){
            mp[50]++;
            if(mp[25]>0){
                mp[25]--;
            }else{
                f = 0;
                break;
            }
        }else{
            if(mp[50]>0 && mp[25]>0){
                mp[50]--;
                mp[25]--;
            }else if(mp[25]>=3){
                mp[25]-=3;
            }else{
                f= 0;
                break;
            }
        }
    }
    cout<<(f?"YES\n":"NO\n");

    return 0;
}