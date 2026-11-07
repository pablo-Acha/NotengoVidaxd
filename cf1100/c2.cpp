#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef vector<ll> vll;

ll gaus(ll n){return n*(n+1) /2;}


int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    ll t;cin>>t;
    while (t--)
    {
        ll n;cin>>n;
        vll arr(n);for(auto &a:arr)cin>>a;
        vll sum(n);
        vll sumb(n);
        sum[0] = abs(arr[0]);
        sumb[0] = arr[0]<0?arr[0]*-1:0;
        ll ss= arr[0];
        for (int i = 1; i < n; i++)
        {
            sumb[i] = sumb[i-1];
            if(arr[i]<0)sumb[i] += abs(arr[i]);
            sum[i] = sum[i-1]+abs(arr[i]);
            ss += arr[i];
            }
        ll iz = -1,der = -1;
        ll dif = 0;
        if(sum[n-1] == abs(ss)){
            cout<<"0\n\n";
            continue;
        }
        // for(auto a:sumb){
        //     cout<<a<<" ";
        // }
        // cout<<"\n";
        for (int i = n - 1; i >= 1; i--)
        {
            if(arr[i]>0){
                ll aux = sumb[i-1]-arr[i];
                if(aux>dif){
                    dif = aux;
                    iz = i-1;
                    der = i;
                }
            }
        }
        if(iz == der){
            cout<<"0\n\n";
        }else{
            ll f = 1;
            vll res;
            for (int i = iz; i >= 0; i--)
            {
                if(arr[i]*f >0){
                    f *=-1;
                    res.push_back(i+1);
                }
            }
            res.push_back(der+1);
            cout<<res.size()<<"\n";
            for(auto &a:res)cout<<a<<" ";
            cout<<"\n";
        }
    }
         

    return 0;
}