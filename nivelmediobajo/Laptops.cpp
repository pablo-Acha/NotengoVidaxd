#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef vector<ll> vll;

int main(){
    int n;cin>>n;
    vector<pair<ll,ll>> arr(n);
    for (int i = 0; i < n; i++)
    {
        auto &[a,b] = arr[i];
        cin>>a>>b;
    }
    sort(arr.begin(),arr.end(),greater<pair<ll,ll>>());
    bool f = 0;
    ll mn = 1e9;
    ll v = 1e9;
    for (int i = 0; i < n; i++)
    {
        if(mn<arr[i].second && v>arr[i].first){
            f = 1;
            break;
        }else if(mn>arr[i].second){
            mn = arr[i].second;
            v = arr[i].first;
        }
    }
    cout<<(f?"Happy Alex\n":"Poor Alex\n");
    
    return 0;
}