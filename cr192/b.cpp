#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef vector<ll> vll;
typedef  pair<int,int> pii;
typedef  pair<ll,ll> pll;
typedef  vector<int> vi;

#define all(x) (x).begin(), (x).end()

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    ll t;cin>>t;
    while(t--){
        ll n;cin>>n;
        vll arr(n);for(auto &a:arr)cin>>a;
        ll i = 0;
        ll cnt =0; 
        bool f = 0,f1 = 0;
        for (; i < n-2; i++)
        {
            if(arr[i] == 1){
                cnt++;
            }else{
                cnt--;
            }
            if(cnt >=0){
                i++;
                f  = 1;
                break;
            }
        }
        while(cnt && i< n-2 && arr[i]>2){
            i++;
            cnt--;
        }
        cnt = 0;
        for (; i < n-1; i++)
        {
            if(arr[i] <= 2){
                cnt++;
            }else{
                cnt--;
            }
            if(cnt >=0){
                i++;
                f1= 1;
                break;
            }
        }
        if(f &&f1){
            cout<<"YES\n";
        }else{
            cout<<"NO\n";
        }
        
    }

    return 0;
}