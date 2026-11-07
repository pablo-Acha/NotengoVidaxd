#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef vector<ll> vll;
int main(){
    int n;cin>>n;
    vector<vll> arr(3);
    for (ll i = 0,a; i < n; i++)
    {
        cin>>a;
        a--;
        arr[a].push_back(i+1);
    }
    ll mn= min(arr[0].size(),min(arr[1].size(),arr[2].size()));
    cout<<mn<<"\n";
    for (int i = 0; i < mn ; i++)
    {
        cout<<arr[0][i]<<" "<<arr[1][i]<<" "<<arr[2][i]<<"\n";        
    }
    
    return 0;
}
