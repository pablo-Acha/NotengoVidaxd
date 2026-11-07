#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef vector<ll> vll;
int main(){
    int n;cin>>n;
    int mi = 0,ci = 0;
    for (int i = 0,a,v; i < n; i++)
    {
        cin>>a>>v;
        if(a>v){
            mi++;
        }else if(v>a){
            ci++;
        }
    }
    if(mi>ci){
        cout<<"Mishka \n";
    }else if(ci>mi){
        cout<<"Chris \n";
    }else{
        cout<<"Friendship is magic!^^ \n";
    }
    return 0;
}
