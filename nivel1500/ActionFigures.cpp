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
        string arr;
        cin>>arr;
        deque<ll> cola;
        ll res = 0;
        for (int i = n - 1; i >= 0; i--)
        {
            if(arr[i] == '1'){
                cola.push_front(i+1);
            }else{
                res+= i+1;
                if(!cola.empty())cola.pop_back();
            }
        }
        while(!cola.empty()){
            res += cola[0];
            cola.pop_front();
            if(!cola.empty())cola.pop_back();
        }
        cout<<res<<"\n";
    }

    return 0;
}