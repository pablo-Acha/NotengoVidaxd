#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef vector<ll> vll;

ll guas(ll n){return n*(n+1) /2;}

ll f(char s){
    if(s == 'S' || s == 'N'){

    }else {

    }
    if(s == 'S' || s == 'N'){

    }else {
        
    }

}
int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    ll n;cin>>n;
    vll arr(n);for(auto &a:arr)cin>>a;
    multiset<ll> ml;
    multiset<ll> mr;
    ml.insert(arr[0]);
    for (int i = 1; i < n; i++)
    {
        ml.insert(arr[i]);
    }
    for (int i = 0; i < n; i++)
    {
        
    }
    
    
    return 0;
}