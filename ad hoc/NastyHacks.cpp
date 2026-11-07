#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef vector<ll> vll;

int main(){
    int n;cin>>n;
    for (int i = 0; i < n; i++)
    {
        ll a,b,c;cin>>a>>b>>c;
        b -= c;
        if(a>b){
            cout<<"do not advertise\n";
        }else if(b>a){
            cout<<"advertise\n";
        }else{
            cout<<"does not matter\n";
        }
    }
    
    return 0;
}   