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
        string s;cin>>s;
        map<char,bool> mp;
        for (int i = 0; i < n; i++)
        {
            mp[s[i]] = 0;
        }
        ll mn = 1e9;
        for(auto [a,v]:mp){
            ll cnt = 0;
            for (int i = 0,j = n-1; i <=j ; )
            {
                // cout<<s[i]<<" "<<s[j]<<"\n";
                if(s[i]!= s[j] ){
                    if(s[i] == a){
                        i++;
                        cnt++;
                    }else if(s[j] == a){
                        j--;
                        cnt++;
                    }else{
                        cnt  = 1e9;
                        break;
                    }

                }else{
                    j--;
                    i++;
                }
            }
            mn = min(mn,cnt);
        }
        cout<<(mn == 1e9?-1:mn)<<"\n";
    }   
       
    return 0;
}