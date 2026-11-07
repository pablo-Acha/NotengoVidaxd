#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef vector<ll> vll;


int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    long double n,k;cin>>n>>k;
    vector<long double> arr(min(n,k-1));
    long double pi = 1/n;
    for (int i = 1,j = 0; i <= min(n,k-1); i++,j++)
    {
        long double aux =i; 
        while(aux<=k-1){
            aux*=2;
            pi *=0.5;
        }
        arr[j] = pi;
        pi = 1/n;
    }
    long double res = 0;
    for (int i = 0; i < min(n,k-1); i++)
    {
        res+= arr[i];
    }
    // cout<<res<<"\n";

    long double aux  = pi;
    for (int i = min(n,k-1)+1; i <= n; i++)
    {
        res +=pi;
    }
    cout << fixed << setprecision(9) << res << "\n";
    return 0;
}