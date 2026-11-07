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

    ll t;cin>>t;
    while(t--){
        ll n;cin>>n;
        vll arr(n);for(auto &a:arr)cin>>a;
        sort(all(arr));
        ll turnos = 0, sum = 0;
        ll l = 0, r= n-1;
        ll L = 1,R = 1;
        while(l<r){
            if(L<R){
                turnos+= arr[l+1]-arr[l];
                sum += (arr[l+1]-arr[l] )* L;
                L++;
                l++;
            }else{
                turnos+= arr[r]-arr[r-1];
                sum += (arr[r]-arr[r-1] )* R;
                R++;
                r--;
            }
        }
        cout<<sum<<" "<<turnos<<"\n";
    }

    return 0;
}