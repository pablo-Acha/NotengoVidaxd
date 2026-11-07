#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef vector<ll> vll;
typedef  pair<int,int> pii;
typedef  pair<ll,ll> pll;
typedef  vector<int> vi;

#define all(x) (x).begin(), (x).end()

void ff(ll f,ll n,set<ll> &st, vll &arr){
    ll acc = 0, acc2 = 0;
    ll mn = 0, mx = 0;
    for (int i = f+1; i < n; i++)
    {
        acc = max(acc+arr[i],0LL);
        mx =max(acc,mx);
        acc2 =min(acc2+arr[i],0LL);
        mn= min(acc2,mn);
    }
    for (int i = mn; i <= mx; i++)
    {
        st.insert(i);
    }
    acc = 0, acc2 = 0;
    mn = 0, mx = 0;
    for (int i = f-1; i >=0; i--)
    {
        acc = max(acc+arr[i],0LL);
        mx =max(acc,mx);
        acc2 =min(acc2+arr[i],0LL);
        mn= min(acc2,mn);
    }
    for (int i = mn; i <= mx; i++)
    {
        st.insert(i);
    }
}


int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    ll t;cin>>t;
    while(t--){
        ll n;cin>>n;
        vll arr(n);for(auto &a:arr)cin>>a;
        ll f= -1;
        for (int i = 0; i < n && f == -1; i++)
        {
            if(arr[i]<-1 || arr[i]>1){f = i;}
        }
        // cout<<f<<" "<<arr[f]<<"\n";
        set<ll> st;st.insert(0);
        ff(f,n,st,arr);
        if(f!=-1){
            ll mx= 0,mn = 0, l = 0,r = 0;
            ll acc = 0,acc2 = 0;
            for (int i = f+1; i < n; i++)
            {
                acc = acc+arr[i];
                mx =max(acc,mx);
                mn= min(acc,mn);
            }
            r+= mx;l += mn;
            for (int i = mn; i <= mx; i++)
            {
                st.insert(i);
            }
            mn = 0,mx = 0;
            acc = 0;
            for (int i = f - 1; i >= 0; i--)
            {
                acc = acc+arr[i];
                mx =max(acc,mx);
                mn= min(acc,mn);
            }
            r+= mx;l+= mn;
            // cout<<mx<<" "<<mn<<"\n";
            for (int i = mn; i <= mx; i++)
            {
                st.insert(i);
            }
            // cout<<l<<"\n";
            for (int i = arr[f]+l; i <= arr[f]+r; i++)
            {
                st.insert(i);
            }
        }
            cout<<st.size()<<"\n";
            for(auto x:st)cout<<x<<" ";cout<<"\n";
        
    }

    return 0;
}