#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef vector<ll> vll;
int main(){
    int n,k;cin>>n>>k;
    vll arr(n-1);
    ll j = 0;
    k--;
    for (int i = 0; i < n-1; i++)
    {
        cin>>arr[i];
    }
    bool f = 0;
    while (j<=k)
    {
        if(j == k){f = 1;break;}
        j += arr[j];
    }
    cout<<(f?"YES":"NO")<<"\n";


    return 0;
}