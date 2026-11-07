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
        set<int> st;
        vector<int> brr(n);for(auto &a:brr){cin>>a;st.insert(a);}
        vector<int> arr = brr;
        reverse(brr.begin(),brr.end());
        int res = 0;
        for(auto a:st){
            int curr = 0;
            int men = 0, may = 0;
            int p = 0;
            for (int i = 0; i < n; i++)
            {
                curr++;
                men += (arr[i]<a);
                may += (arr[i]>a);
                if(curr&1){
                    if(men<=curr/2 && may<=curr/2){
                        men = 0;
                        may = 0;
                        curr = 0;
                        p++;
                    }
                }         
            }
            if(curr > 0)p = 0;
            men = 0, may = 0;
            int s = 0;
            curr = 0;
            for (int i = 0; i < n; i++)
            {
                curr++;
                men += (brr[i]<a);
                may += (brr[i]>a);
                if(curr&1){
                    if(men<=curr/2 && may<=curr/2){
                        men = 0;
                        may = 0;
                        curr = 0;
                        s++;
                    }
                }
            }
            if(curr>0)s = 0;
            res = max(res,max(s,p));
        }
        cout<<res<<"\n";
    }   
    return 0;
}