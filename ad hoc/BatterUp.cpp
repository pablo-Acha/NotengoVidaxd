#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef vector<ll> vll;

int main(){
    int n;cin>>n;
    double res  = 0;
    double h = 0;
    for (int i = 0,a; i < n; i++)
    {
        cin>>a;

        if(a == -1)continue;
        h++;
        res+=a;
    }
    res = res/h;
    cout<<res<<"\n";
    return 0;
}