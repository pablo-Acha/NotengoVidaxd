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
        vll brr(n+1);
        vll arr(n);
        for (int i = 0,a; i < n; i++)
        {
            cin>>a;
            brr[a] = i;
            arr[i] = a; 
        }
        vll res(n);
        // for(auto a:brr){
        //     cout<<a<<" ";
        // }
        // cout<<rnl;
        for (int i = 0,j = n; i < n; i++,j--)
        {
            if(arr[i]!=j){
                ll x = i;
                // cout<<arr[i]<<" ";
                // cout<<brr[j]<<rnl;
                for (int h = brr[j]; h >=i; h--,x++)
                {
                    res[x] = arr[h];
                }
        //         for(auto a:res){
        //     cout<<a<<" ";
        // }
        // cout<<rnl;
                x = brr[j]+1;
                for (int h = x; h < n; h++)
                {
                    res[h] = arr[h];
                }
                break;
            }
            res[i] =arr[i];
        }
        for(auto a:res){
            cout<<a<<" ";
        }
        cout<<rnl;
    }
    
    return 0;
}