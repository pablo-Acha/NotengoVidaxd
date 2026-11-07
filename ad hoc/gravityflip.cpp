#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef vector<long long> vll;
void pr(vll &arr){for(auto a:arr)cout<<a<<"\n";cout<<"\n";}
int main(){
    ll n;cin>>n;
    vll arr(n);
    for (int i = 0; i < n; i++)
    {
        cin>>arr[i];
    }
    sort(arr.begin(),arr.end());
    for(auto a:arr)cout<<a<<" ";
    cout<<"\n";
    return 0;
}