#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t;cin>>t;
    while(t--){
        ll a,b,c;cin>>a>>b>>c;
        ll mo = c%b;
        ll mn = min(a,b);
        if((c/b)%2 == 0){
            cout<<(a-mo<0?0:a-mo)<<"\n";
        }else{
            cout<<(mn-mo<0?0:mn-mo)<<"\n";
        }
        
    }    
    return 0;
}