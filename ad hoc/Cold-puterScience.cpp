#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef vector<ll> vll;

int main(){
    int n;cin>>n;
    ll res = 0;
    for (int i = 0,a; i < n; i++)
    {
        cin>>a;
        if(a<0) {
            res++;
        }
    }
    cout<<res<<"\n";
    return 0;
}