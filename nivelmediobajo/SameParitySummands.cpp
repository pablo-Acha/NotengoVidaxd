#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef vector<ll> vll;
// #include <iomanip>

int main(){
    ll t;cin>>t;
    while (t--)
    {
        ll n,k;cin>>n>>k;
        if(n>=k &&((n-(k-1))&1 || (((k-1)%2== 0) &&(n-(k-1))%2 == 0) && (n>=k*2))){
            cout<<"YES\n";
            if((n-(k-1))&1){
                cout<<(n-(k-1))<<" ";
                for (int i = 0; i < k-1; i++)
                {
                    cout<<1<<" ";
                }
            }else{
                cout<<(n-((k-1)*2))<<" ";
                for (int i = 0; i < k-1; i++)
                {
                    cout<<2<<" ";
                }
            }
            cout<<"\n";
            
        }else{
            cout<<"NO\n";
        }
    }
    
    return 0;
}