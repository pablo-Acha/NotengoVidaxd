#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef vector<ll> vll;
int main(){
    int n;cin>>n;
    int a = 0,b = 0;
    for (int i = 0,x,y; i < n; i++)
    {
        cin>>x>>y;
        a+=x;
        b+=y;
    }
    int mn1 = min(a,n-a);
    int mn2 = min(b,n-b);
    cout<<mn1+mn2<<"\n";
}
