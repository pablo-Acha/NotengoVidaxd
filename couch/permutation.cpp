#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef vector<ll> vll;
typedef  pair<int,int> pii;
typedef  pair<ll,ll> pll;
typedef  vector<int> vi;

#define all(x) (x).begin(), (x).end()

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    ll n;cin>>n;
    vll arr(n);
    for (int i = 0; i < n; i++)
    {
        arr[i]= i+1;
    }
    while (true)
    {
        for (int i = 0; i < n; i++)
        {
            if(i)cout<<" ";
            cout<<arr[i];
        }
        cout<<"\n";
        if(!next_permutation(all(arr)))break;
    }
    

    return 0;
}