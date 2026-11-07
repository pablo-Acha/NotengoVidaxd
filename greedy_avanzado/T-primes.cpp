#include<bits/stdc++.h>
using namespace std;
int main(){
    int t;cin>>t;
    vector<long long> primos(1e6+1,1);
    primos[0]= 0;
    primos[1]= 0;
    for (int i = 2; i <= 1e6; i++)
    {
        if(!primos[i])continue;
        for (int j = i*2; j <= 1e6; j+=i)
        {
            primos[j] = 0;
        }
    }
    
    for (int i = 0; i < t; i++)
    {
        long long a;cin>>a;
        long long x = sqrt(a);
        if(a>3 && (x*x )== a && primos[x]){
            cout<<"YES\n";
        }else{
            cout<<"NO\n";
        }
    }
    
    return 0;
}