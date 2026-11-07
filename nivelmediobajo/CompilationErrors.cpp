#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef vector<ll> vll;

int main(){
    int n;cin>>n;
    vll arr(n),brr(n-1),crr(n-2);
    for(auto &a:arr)cin>>a;    
    for(auto &a:brr)cin>>a;    
    for(auto &a:crr)cin>>a;
    sort(arr.begin(),arr.end());
    sort(brr.begin(),brr.end());
    sort(crr.begin(),crr.end());
    bool f = 0;
    for (int i = 0; i < n-1; i++)
    {
        if(arr[i] != brr[i]){
            cout<<arr[i]<<"\n";
            f = 1;
            break;
        }
    }
    if(!f)cout<<arr[n-1]<<"\n";
    f = 0;
    for (int i = 0; i < n-2; i++)
    {
        if(brr[i] != crr[i]){
            cout<<brr[i]<<"\n";
            f = 1;
            break;
        }
    }
    if(!f)cout<<brr[n-2]<<"\n";
    
    
    return 0;
}