#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef vector<ll> vll;
int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    ll t;cin>>t;
    while(t--){
        ll n,m,h;cin>>n>>m>>h;
        vll arr(n);for(auto &a:arr)cin>>a;
        vll brr(n);
        vll val(n);
        ll act = 1;
        for (int i = 0,b,c; i < m; i++)
        {
            cin>>b>>c;
            b--;
            if(val[b] == act){
                if(brr[b]+c >h){
                    act++;
                    continue;
                }else{
                    brr[b] = brr[b]+c;
                    val[b]  = act;
                }
            }else{
                if(arr[b]+c >h){
                    act++;
                    continue;
                }else{
                    brr[b] = arr[b]+c;
                    val[b]  = act;
                }
            }
        }
        for (int i = 0; i < n; i++)
        {
            if(val[i]!=act){
                brr[i] = arr[i];
            }
        }
        for(auto a:brr){
            cout<<a<<" ";
        }
        cout<<"\n";
    }
    return 0;
}