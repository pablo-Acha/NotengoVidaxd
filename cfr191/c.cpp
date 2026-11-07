#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef vector<ll> vll;

ll guas(ll n){return n*(n+1) /2;}

const ll MOD = 998244353;
int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    ll t;cin>>t;
    while(t--){
        ll n,k;cin>>n>>k;
        string s;cin>>s;
        string res(n,'0');
        vll pre(n),suf(n);
        ll l = 0, r = 0;
        for (int i = 0, j = n-1; i < n; i++,j--){
            pre[i] = l;
            suf[j] = r;
            l += s[i] == '('; 
            r += s[j] == ')'; 
        }

        ll i =0, j = n-1;
        l = 0, r = 0;
        while(k && i<n && j>=0){
            if(s[i]!='('){i++;continue;}
            if(s[j]!=')'){j--;continue;}
            ll a = suf[i]-r,b= pre[j]-l;
            if(a>b){
                l++;
                res[i] ='1';
                i++;
            }else if(a<b){
                r++;
                res[j] ='1';
                j--;
            }else if(a!=0){
                l++;
                res[i] ='1';
                i++;
            }else{
                j--;
                i++;
                continue;
            }
            k--;
        }
        while(k && i<n){
            if(s[i] == '(')res[i] = '1';
            k--;            
            i++;
        }
        while(k && j>=0){
            if(s[j] == ')')res[j] = '1';
            k--;            
            j--;
        }
        cout<<res<<"\n";
             
    }
    return 0;
}