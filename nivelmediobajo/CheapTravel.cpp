#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef vector<ll> vll;

int main(){
    int a,b,c,d;cin>>a>>b>>c>>d;
    int x = d/b;
    if(x>=c){
        cout<<a*c<<"\n";
    }else{
        int res = ((a/b) *d) + min((a%b>0)*d,(a%b)*c); 
        cout<<res<<"\n";
    } 
    return 0;
}