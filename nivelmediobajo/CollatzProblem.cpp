#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef vector<ll> vll;
const ll MOD = 1e9+7;

ll gaus(ll n){
    return (n*(n+1))/2;
}
bool f(ll x, ll p){
    if((x == 1 && !(p&1)) || (x == 2 &&(p&1))){
        return 1;
    }
    return 0;
}

ll coll(ll n ){
    ll res = 0;
    if(n&1){
        res= (n*3)+1;
    }else{
        res = n/2;
    }   
    return res;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    ll n;cin>>n;
    vll arr(1e6+1);
    arr[1] = n;
    set<ll> st;
    st.insert(n);
    for (int i = 2; i <= 1e6; i++)
    {
        arr[i] = coll(arr[i-1]); 
        if(st.find(arr[i]) !=st.end()){
            cout<<i<<"\n";
            break;
        }else{
            st.insert(arr[i]);
        }
    }
        
    return 0;
}