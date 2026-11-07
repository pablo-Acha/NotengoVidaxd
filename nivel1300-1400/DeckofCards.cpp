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
        string s;cin>>s;
        ll l = 0,r = 0, inc = 0;
        string res(n,'+');
        for (int i = 0; i < k; i++)
        {
            if(s[i] == '0'){
                l++;
            }else if(s[i] == '1'){
                r++;
            }else{
                inc++;
            }
        }

        if(k == n){
            for (int i = 0; i < n; i++)
            {
                cout<<"-";
            }
            cout<<"\n";
            continue;
        }
        ll j = 0;
        while(j<l){res[j] = '-';j++;}
        j = n-1;
        while(j>=n-r){res[j] = '-';j--;}        
        r = n-r-1;
        while(l<=r && inc){
            res[r] = '?';
            res[l] = '?';
            inc--;
            r--;
            l++;
        }
        for(auto a:res)cout<<a;
        cout<<"\n";
        
    }
    return 0;
}