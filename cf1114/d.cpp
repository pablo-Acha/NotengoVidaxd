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
        string a,b;cin>>a>>b;
        if(n<=2){
            if(a == b){
                cout<<0<<"\n";
            }else{
                cout<<"-1\n";
            }
            continue;
        }
        vll impA, impB;
        vll parA, parB;
        for (int i = 0; i < n; i++)
        {
            if(i&1){   
                if(a[i] == '1')parA.push_back(i); 
                if(b[i] == '1')parB.push_back(i);
            }else{
                if(a[i] == '1')impA.push_back(i); 
                if(b[i] == '1')impB.push_back(i);

            }
        }
        if(parA.size() == parB.size() && impA.size() == impB.size()){
            ll res = 0;
            for (int i = 0; i < parA.size(); i++)
            {
                res+= abs(parA[i]-parB[i])/2;
            }
            for (int i = 0; i < impA.size(); i++)
            {
                res+= abs(impA[i]-impB[i])/2;
            }
            cout<<res<<"\n";
        }else{
            cout<<"-1\n";
        }
    }

    return 0;
}