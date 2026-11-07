#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef vector<ll> vll;

int main(){
    int t;cin>>t;
    while(t--){
        ll n;cin>>n;
        vll arr(n);
        ll imp = 0,par = 0;
        for (int i = 0; i < n; i++)
        {
            cin>>arr[i];
            if(arr[i]&1){
                imp++;
            }else{
                par++;
            }
        }
        if(!(imp&1) && !(par&1)){
            cout<<"YES\n";
        }else if((imp&1) && (par&1)){
            bool x = 0;
            sort(arr.begin(),arr.end());
            for (int i = 1; i < n; i++)
            {
                if(arr[i]-arr[i-1] == 1){
                    x= 1;
                    break;
                }
            }
            cout<<(x?"YES\n":"NO\n");            
        }else{
            cout<<"NO\n";
        }
    }
    
    return 0;
}