#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int main(){
    ll n, x;cin>>n>>x;
    ll temp = n-x;
    cout<<7-(temp%7)<<endl;
    return 0;
}