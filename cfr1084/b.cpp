#include<bits/stdc++.h>
using namespace std;
#define rnl "\n"
typedef long long ll;
typedef vector<ll> vll;



int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    ll t;cin>>t;
    while (t--)
    {
        int n;cin>>n;
        vll arr(n);for(auto &a:arr)cin>>a;
        ll mx = 0;
        bool f = 0;
        for (int i = 0; i < n; i++)
        {
            if(arr[i] < mx){
                f = 1;
            
                break;
            }
            mx = max(arr[i],mx);
        }
        if(f){
            cout<<1<<"\n";
        }else{
            cout<<n<<"\n";
        }
    }
    
    return 0;
}