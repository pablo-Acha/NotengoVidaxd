#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef vector<ll> vll;
int main(){
    int t;cin>>t;
    while(t--){
        long long a,b,c,k;cin>>a>>b>>c>>k;
        long long mx = max(max(a,b),c);
        long long r = mx-a + mx-b +mx-c;
        if(k-r>=0 && ((k-r)%3 == 0)){
            cout<<"YES\n";
        }else{
            cout<<"NO\n";
        }
    }
    return 0;
}