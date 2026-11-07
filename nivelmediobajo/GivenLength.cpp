#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef vector<ll> vll;


int main(){
    ll n,s;cin>>n>>s;
    vll arr(n);
    arr[0] = 1;
    if(s == 0 && n == 1){
        cout<<0<<" "<<0<<"\n";
        return 0;
    }
    if(s == 0 || n*9<s){
        cout<<-1<<" "<<-1<<"\n";
        return 0;
    }
    ll sum = 1;
    for (int i = n - 1; i >= 0; i--)
    {
        if(sum<s){
            ll aux = min(9LL,s-sum);
            sum+=aux;
            arr[i] +=aux;
        }else{
            break;
        }        
    }
    vll brr(n);
    sum = 0;
    for (int i = 0; i < n; i++)
    {
        if(sum<s){
            ll aux = min(9LL,s-sum);
            sum+=aux;
            brr[i] +=aux;
        }else{
            break;
        }   
    }
    for(auto a:arr)cout<<a;
    cout<<" ";
    for(auto a:brr)cout<<a;
    cout<<"\n";
    
    return 0;
}