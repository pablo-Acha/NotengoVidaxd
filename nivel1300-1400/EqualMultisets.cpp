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
        ll n,k;cin>>n>>k;
        vll arr(n);for(auto &a:arr)cin>>a;
        vll brr(n);for(auto &a:brr)cin>>a;
        set<ll> vi;
        for (int i = n-k; i < k; i++)
        {
            vi.insert(arr[i]);            
        }
        bool f = 1;
        if(n-k<k)sort(brr.begin()+(n-k),brr.begin()+k,greater<ll>());
        for (int i = n-k; i < k; i++)
        {
            if(brr[i] == -1){
                ll x = *vi.begin();
                vi.erase(vi.begin());
                brr[i] = x;
            }else if(vi.find(brr[i]) == vi.end()) {
                f = 0;
                break;
            }else{
                vi.erase(vi.find(brr[i]));
            }     
        }
        if(!f){
            cout<<"NO\n";
        }else{
            for (int i = 0; i < n-k; i++)
            {
                if(brr[i] == -1){
                    brr[i] = arr[i];
                }else if(brr[i]!= arr[i]){
                    f = 0;
                }
            }
            for (int i = k; i < n; i++)
            {
                if(brr[i] == -1){
                    brr[i] = arr[i];
                }else if(brr[i]!= arr[i]){
                    f = 0;
                }
            }
            cout<<(f?"YES\n":"NO\n");
        }
    }
    return 0;
}