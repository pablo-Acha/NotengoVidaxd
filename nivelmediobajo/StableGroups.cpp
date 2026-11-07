#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef vector<ll> vll;
// #include <iomanip>
ll f(char x){
    return x-'0';
}
int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
        ll n,k,x;cin>>n>>k>>x;
        vll arr(n);for(auto &a:arr)cin>>a;
        sort(arr.begin(),arr.end());
        // ll res = 0,aux = 0;
        vll sob;
        for (int i = 1; i < n; i++)
        {
            if(arr[i]-arr[i-1]>x){
                sob.push_back(arr[i]-arr[i-1]);
            }
        }
        ll res = sob.size();
        sort(sob.begin(),sob.end());
        for (int i = 0; i < sob.size(); i++)
        {
            ll des = sob[i]/x;
            
            if(sob[i]%x ==0){
                des--;
            }
            if(des<=k){
                res= max(res-1,0LL);
                k = k-des; 
            }
        }
        res++;
        cout<<res<<"\n";        

        
    
    return 0;
}