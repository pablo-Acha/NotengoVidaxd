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
        ll n,x,y;cin>>n>>x>>y;
        vll arr(n);
        if(n&1){
            ll aux = 1;
            for (int i = 0; i < n-1; i++)
            {
                arr[i] = aux;
                aux = 1-aux;
            }
            arr[n-1] = 2;
            if(x!=n && y!=n){
                if((x&1) && (y&1)){
                    arr[y-1]++;
                }else if(!(x&1) && !(y&1)){
                    if(x == 2){
                        arr[0] = 0;
                        arr[n-1] = 1;
                    }
                    arr[x-1]+=2;
                }
            }   
        }else{
            ll aux = 1;
            for (int i = 0; i < n-1; i++)
            {
                arr[i] = aux;
                aux = 1-aux;
            }
            if((x&1) && (y&1)){
                arr[y-1]++;
            }else if(!(x&1) && !(y&1)){
                arr[x-1]+=2;
            }
        }
        for (int i = 0; i < n; i++)
        {
            cout<<arr[i]<<" ";
        }
        cout<<"\n";
        
    }

    return 0;
}