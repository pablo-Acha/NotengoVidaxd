#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef vector<ll> vll;

ll gaus(ll n){return n*(n+1) /2;}


int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    ll t;cin>>t;
    while(t--){
        ll n;cin>>n;
        vll arr(n+2);for(auto &a:arr)cin>>a;
        sort(arr.begin(),arr.end());
        ll mx = arr[n+1];
        ll sum = 0;
        for (int i = 0; i < n+1; i++){
            sum+=arr[i];
        }
        ll delet = -1;
        for (int i = 0; i < n+1; i++){
            if(mx == sum-arr[i]){
                delet = i;
                break;
            }
        }

        if(delet == -1){
            ll mxA = arr[n];
            if(mxA == sum-mxA){
                for (int i = 0; i < n; i++)
                {
                    cout<<arr[i]<<" ";
                }
                cout<<"\n";
            }else{
                cout<<-1<<"\n";
            }
        }else{
            for(int i = 0; i < n+1; i++){
                if(i == delet)continue;
                cout<<arr[i]<<" ";
            }
            cout<<"\n";
        }
    }

    return 0;
}