#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef vector<ll> vll;
typedef  pair<int,int> pii;
typedef  pair<ll,ll> pll;
typedef  vector<int> vi;

#define all(x) (x).begin(), (x).end()
set<ll> st;
ll mx = 0;
ll f1(ll act, vll &arr, vll &ind, vll &iz){
    ll n = arr.size();
    ll next = ind[*st.upper_bound(act)];
    while(next!=-1){
        act = arr[next];
        if(act ==mx)return act;
        next = iz[next];
    }
    return act;
}

ll f2(ll act, vll &arr, vll &und, vll &der){
    ll n = arr.size();
    ll next = und[*st.upper_bound(act)];
    while(next!=-1){
        act = arr[next];
        if(act == mx)return act;
        next = der[next];
    }
    return act;
}

int main() {
    // ios::sync_with_stdio(false);
    // cin.tie(nullptr);

    ll n,m;cin>>n>>m;
    // ll mx = 0;
    vll arr(n);for(auto &a:arr){cin>>a;st.insert(a);mx= max(a,mx);}
    vll der(n),iz(n);
    vll ind(m+1,-1),und(m+1,-1);
    for (int i = 0; i < n; i++)
    {
        ind[arr[i]] = i;
        if(arr[i]!=mx)iz[i] = ind[*st.upper_bound(arr[i])];        
        else iz[i] = -1;
    }
    for(int i = n - 1; i >= 0; i--)
    {
        und[arr[i]] =i;
        if(arr[i]!=mx)der[i] = und[*st.upper_bound(arr[i])];
        else der[i] = -1;    
    }
    ll act = 0;
    ll res = 0;
    while(act<mx){
        res++;
        act= max(f1(act,arr,ind,iz),f2(act,arr,und,der));
    }
    cout<<st.size()<<" "<<res<<"\n";
    // for(auto x:der)cout<<x<<" ";cout<<"\n";
    // for(auto x:iz)cout<<x<<" ";cout<<"\n";
    
    return 0;
}