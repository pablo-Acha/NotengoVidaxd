#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef vector<ll> vll;

ll guas(ll n){return n*(n+1) /2;}
int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    ll t;cin>>t;
    while(t--){
        ll n;cin>>n;
        vll arr(n);for(auto &a:arr)cin>>a;
        deque<ll> as,bs,cs,ds,fi;
        for (int i = 0; i < n; i++)
        {
            if(arr[i]%6 == 0){
                as.push_back(arr[i]);
            }else if(arr[i]%3 == 0){
                bs.push_back(arr[i]);
            }else if(arr[i]%2 == 0){
                cs.push_back(arr[i]);
            }else{
                ds.push_back(arr[i]);
            }
        }
        for(auto a:bs){
            fi.push_back(a);
        }
        for(auto a:ds)fi.push_back(a);
        for(auto a:cs)fi.push_back(a);
        ll h = 0;
        for(auto a:as){
            if(h&1)fi.push_back(a);
            else fi.push_front(a);
            h++;
        }
        for (int i = 0; i < n; i++)
        {
            cout<<fi[i]<<" ";
        }
        cout<<"\n";
    }
       
    return 0;
}