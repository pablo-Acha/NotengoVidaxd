#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef vector<ll> vll;

int main(){
    ll a,b,c,d,e;cin>>a>>b>>c>>d>>e;
    ll aux = a+b+c+d+e;
    if(aux%5 ==0 && aux!=0){
        cout<<aux/5<<"\n";
    }else{
        cout<<-1<<"\n";
    }
    return 0;
}