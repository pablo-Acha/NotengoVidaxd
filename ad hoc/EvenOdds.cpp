#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef vector<long long> vll;
void pr(vll &arr){for(auto a:arr)cout<<a<<"\n";cout<<"\n";}
int main(){
    ll n,k;cin>>n>>k;
    if(k>((n/2)+(n&1))){
        ll res = (k-((n/2)+(n&1)))*2;
        cout<<res<<"\n";
    }else{
        ll res = k+(k-1);
        cout<<res<<"\n";

    }
    return 0;
}