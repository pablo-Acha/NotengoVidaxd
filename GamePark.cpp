#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef vector<long long> vll;

int main(){
    ll n;cin>>n;
    vector<vll> arr(4,vll(n));
    for (int i = 0; i < 4; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cin>>arr[i][j];
        }
    }
    vector<vll> res(4,vector<ll>(2));
    // ll odd = 0,par = 0;
    for (int i = 0; i < 4; i++)
    {
        vll odd(n),par(n);
        for (int j = 0; j < n; j++)
        {
            if(arr[i][j] < 0)continue;
            if(j>1){
                res[i][0]+= max(res[i-1][0],res[i-2][1]);
                res[i][1]+= max(res[i-1][1],res[i-2][0]);
            }else if(j>0){
                res[i][0]+= res[i-1][0];
                res[i][1]+= res[i-1][1];
            }else{
                
            }
        }
        if(i>1){
            res[i][0]+= max(res[i-1][0],res[i-2][1]);
            res[i][1]+= max(res[i-1][1],res[i-2][0]);
        }else if(i>0){
            res[i][0]+= res[i-1][0];
            res[i][1]+= res[i-1][1];
        }
    }
    ll a = max(res[3][0],res[3][1]);
    cout<<a<<"\n";
    return 0;
}