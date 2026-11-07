#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef vector<ll> vll;

ll guas(ll n){return n*(n+1) /2;}

ll f(deque<ll> brr){
    ll l = 0;
    ll r = 0;
    ll m = brr.size();
    for (int i = 0; i < m; i+=2)
    {
        ll aux = max(abs(brr[i])+l,abs(brr[i+1])+r);
        l= aux;
        r+= brr[i+1];
    }
    return max(l,r);
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    ll t;cin>>t;
    while(t--){
        ll n;cin>>n;
        vll arr(n);for(auto &a:arr)cin>>a;
        deque<ll> brr;
        for (int i = 0; i < n;)
        {
            if(i<n && arr[i]<0){
                ll acc = 0;
                while(i<n && arr[i]<0){
                    acc+= arr[i];
                    i++;
                }
                brr.push_back(acc);
            }
            if(i<n && arr[i]>0){
                ll acc = 0;
                while(i<n && arr[i]>0){
                    acc+= arr[i];
                    i++;
                }
                brr.push_back(acc);
            }
        }
        if(brr.size() == 1){
            cout<<abs(brr[0])<<"\n";
            continue;
        }
        ll res = 0;
        if(brr[0] > 0) res+= brr[0], brr.pop_front();
        if(brr[brr.size()-1] < 0) res+= abs(brr[brr.size()-1]), brr.pop_back();

        deque<ll> crr = brr;
        reverse(crr.begin(),crr.end());
        ll m = brr.size();
        res+= max(f(brr),f(crr));
        cout<<res<<"\n";

        
    }
    
    
    return 0;
}