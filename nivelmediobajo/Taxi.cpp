#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef vector<ll> vll;

int main(){
    int n;cin>>n;
    ll res = 0;
    vector<ll> arr(4);
    for (int i = 0,a; i < n; i++)
    {
        cin>>a;
        arr[a-1]++;
    }
    
    ll p2 = arr[1]%2;
    if(p2){
        arr[0]-=min(2LL,arr[0]);
    }
    if(arr[2]){
        arr[0]-=min(arr[2],arr[0]);
    }
    res+= arr[0]/4 + (arr[0]%4>0)+arr[1]/2 + p2+arr[2]+arr[3];
    cout<<res<<"\n";
    return 0;
}