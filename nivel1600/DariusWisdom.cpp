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
        set<ll> unos,dos;
        for (int i = 0; i < n; i++)
        {
            if(arr[i] == 1)unos.insert(i);
            else if(arr[i] == 2)dos.insert(i);
        }
        vector<pll> res;
        for (int i =  n - 1; i >= 0; i--)
        {
            if(arr[i] == 0){
                if(!unos.empty()){
                    auto x = unos.begin();
                    res.push_back({i+1,*x+1});
                    swap(arr[i],arr[*x]);
                    unos.erase(x);
                    i++;
                }
            }else if(arr[i] == 1){
                if(unos.find(i) != unos.end())unos.erase(unos.find(i));
                if(!dos.empty()){
                    auto x = dos.begin();
                    swap(arr[i],arr[*x]);
                    res.push_back({i+1,*x+1});
                    unos.insert(*x);
                    dos.erase(*x);
                }
            }else{
                if(dos.find(i) != dos.end())dos.erase(dos.find(i));
            }
        }
        cout<<res.size()<<"\n";
        for(auto [x,y]:res)cout<<x<<" "<<y<<"\n";
        
    }

    return 0;
}