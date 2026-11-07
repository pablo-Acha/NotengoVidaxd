#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef vector<ll> vll;


ll ayuda(ll x,vll &arr){
    ll n = arr.size();
    vll mex((n/2)+1);
    for (int i = x,j = x; i >=0 && j<n ; i--,j++)
    {
        if(arr[i] == arr[j])mex[arr[i]] = 1;
        else break;
    }
    ll res = 0;
    for (int i = 0; i < mex.size(); i++)
    {
        if(mex[i] == 0){res = i;break;}
    }
    // for(auto a:mex)cout<<a<<" ";
    // cout<<"\n";
    return res;
}

ll guas(ll n){return n*(n+1) /2;}
int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    ll t;cin>>t;
    while(t--){
        ll n;cin>>n;
        vll arr(2*n);for(auto &a:arr)cin>>a;
        vll aux;
        vll mex(n+1);
        for (int i = 0; i < 2*n; i++)
        {
            if(arr[i] == 0)aux.push_back(i);
            if(aux.size() == 2)break;
        }
        ll ia = aux[0],ib = aux[1];
        bool f1 = 1;
        for (int i = ia,j = ib; i <=j; i++,j--)
        {
            if(arr[i] != arr[j])f1 = 0;
        }
        if(f1){
            
            for (int i = ia,j = ib; i <=j; i++,j--)
            {
                if(arr[i] == arr[j])mex[arr[i]] = 1;
            }
            for (int i = ia,j = ib; i >=0 && j<(2*n); i--,j++)
            {
                if(arr[i] == arr[j])mex[arr[i]] = 1;
                else break;
            }
            ll res = 0;
            for (int i = 0; i <= n; i++)
            {
                if(mex[i] == 0){res = i;break;}
            }
            // cout<<res<<"\n";
            res = max(max(ayuda(ia,arr),ayuda(ib,arr)),res);
            // cout<<"xxx -------"<<"\n";
            cout<<res<<"\n";
        }else{
            ll res = max(ayuda(ia,arr),ayuda(ib,arr));
            cout<<res<<"\n";
        }

    }
       
    return 0;
}