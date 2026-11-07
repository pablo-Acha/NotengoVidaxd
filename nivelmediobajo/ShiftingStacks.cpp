#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef vector<ll> vll;

int main(){
    int t;cin>>t;
    while(t--){
        ll n;cin>>n;
        vll arr(n);for(auto &a:arr)cin>>a;
        ll acc = 0;
        bool f = 0;
        for (int i = 0; i < n; i++)
        {
            if(arr[i]>i){
                acc+=arr[i]-i;                
            }else if(arr[i]<i){
                ll aux = arr[i];
                arr[i]+=min(i-arr[i],acc);
                acc-= min(i-aux,acc);
            }

            if(arr[i]<i){
                f = 1;
                break;
            }
        }
        cout<<(f?"NO\n":"YES\n");
    }   
    return 0;
}