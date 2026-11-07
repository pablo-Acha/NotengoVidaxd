#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef vector<long long> vll;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t;cin>>t;
    while(t--){
        ll n,m,k;cin>>n>>m>>k;
        ll left =k-1, right = n-k;
        ll a = max(left,right),b = min(left,right);
        ll res = 0;
        for (ll i = 1; i <= a; i++)
        {
            ll aux = i*2 - 1;
            if(aux<=m){
                res  = max(res,i+min(m-aux,min(i,b)));
            }
        }
        cout<<res+1<<"\n";
    }
    
    return 0;
}