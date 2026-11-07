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
        vll res(n+1);
        vll arr(n);for(auto &a:arr){cin>>a;res[a]++;}
        sort(all(arr));
        stack<ll> st;
        ll mex = 0;
        for (int i = 0; i < arr.size(); i++)
        {
            if(arr[i]== mex){
                mex++;
            }else if(arr[i]<mex)
            {
                st.push(arr[i]);
            }else{
                if(st.empty()){
                    break;
                }else{
                    mex++;
                    res[mex]+= mex-1-st.top();
                    st.pop();
                }
            }
        }
        mex++;
        while(!st.empty()){
            res[mex] = mex-st.top();
            st.pop();
            mex++;
        }
        for (int i = mex; i < res.size(); i++)
        {
            res[i] = -1;
        }
        for(auto x:res)cout<<x<<" ";cout<<"\n";
        


    }

    return 0;
}