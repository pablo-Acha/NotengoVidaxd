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
        deque<ll> arr(n);for(auto &a:arr)cin>>a;
        ll sal = 0;
        while (arr[n-1] == arr[0])
        {
            arr.push_front(arr[0]);
            arr.pop_back();
            sal++;
            if(sal == n)break;
        }
        if(sal == n){
            cout<<(n-1)*arr[0]<<"\n";
        }else{
            ll res = 0;
            vll brr;
            for (int i = 0; i < n; i++)
            {
                if(i< n-1 && arr[i] == arr[i+1]){
                    // ll cnt = 0;
                    while(i<n-1 && arr[i] == arr[i+1]){
                        res += arr[i];
                        i++;
                    }
                }
                brr.push_back(arr[i]);
            }
            n = brr.size();
            ll mx = *max_element(brr.begin(),brr.end());
            ll aux = 0;
            for (int i = 0; i < n; i++)
            {
                ll l =brr[(i+n-1)%n],r = brr[(i+1)%n]; 
                if(l < brr[i] ) res+= brr[i];
                if(r < brr[i] ) res+= brr[i];
                aux+= brr[i] == mx;
                // cout<<l<<" "<<r<<"\n";
            }
            res-=mx;
            cout<<res<<"\n";
        }
        
    }
    return 0;
}