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
        ll m = n*2;
        ll res = 0;
        for (int i = 0, j = 1; i < n-1; i++,j+=2)
        {
            cout<<"? "<<j<<" "<<j+1<<"\n";
            cout.flush();       
            cin>>res;
            if(res == 1){
                cout<<"! "<<j<<"\n";
                break;
            }
        }
        if(res == 0){
            cout<<"? "<<m-2<<" "<<m-1<<"\n";
            cout.flush();       
            cin>>res;
            if(res == 1){
                cout<<"! "<<m-2<<"\n";
            }else{
                cout<<"? "<<m-3<<" "<<m-1<<"\n";
                cout.flush();       
                cin>>res;
                if(res == 1){
                    cout<<"! "<<m-3<<"\n";
                }else{
                    cout<<"! "<<m<<"\n";
                }
            }
        }
        cout.flush();       

        
    }

    return 0;
}