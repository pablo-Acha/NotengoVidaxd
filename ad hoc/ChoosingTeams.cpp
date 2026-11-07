#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef vector<ll> vll;
int main(){
    int n,k;cin>>n>>k;
    ll res = 0;
    for (int i = 0,a; i < n; i++)
    {
        cin>>a;
        if(a+k>5)continue;
        res++;
    }
    cout<<res/3<<"\n";
    return 0;
}