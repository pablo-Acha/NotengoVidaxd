#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef vector<ll> vll;

int main(){
    int n;cin>>n;
    for (int i = 0; i < n; i++)
    {
        int a,b,c;cin>>a>>b>>c;
        int mn = min(a,b);
        int mx= max(a,b);
        if((mx/mn == c &&(mx%mn == 0))|| mx+mn==c || mx-mn == c|| mx*mn == c){
            cout<<"Possible\n";
        }else{
            cout<<"Impossible\n";
        }
    }
    
    
    return 0;
}   