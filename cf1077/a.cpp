#include<bits/stdc++.h>
using namespace std;
#define rnl "\n"
typedef long long ll;
typedef vector<ll> vll;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    ll t;cin>>t;
    while (t--)
    {
        ll n;cin>>n;
        vll res(n);
        for (int i = n - 1,j = 1,h = n,k = 1; i >= 0; i--,k++)
        {
            if(k&1){
                res[i] = j;
                j++;
            }else{
                res[i] = h;
                h--;
            }
        }
        for(auto a:res){
            cout<<a<<" ";
        }
        cout<<rnl;
    }
    
    return 0;
}