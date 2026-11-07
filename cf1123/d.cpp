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
        priority_queue<ll,vll,greater<ll>> pqim;
        priority_queue<ll,vll,greater<ll>> pqpar;
        stack<ll> stpr;
        stack<ll> stim;
        for (int i = 0; i < n; i++)
        {
            if(i&1){
                pqpar.push(arr[i]);
            }else{
                pqim.push(arr[i]);
            }
        }
        ll last = 0;
        bool act = 1;
        bool f= 1;
        ll cnt = 0;
        while(true){
            if(act){
                while(!pqim.empty() && pqim.top()<=last){
                    stim.push(pqim.top());
                    pqim.pop();
                }
                if(pqim.empty()){
                    while (!pqpar.empty())
                    {
                        stpr.push(pqpar.top());
                        pqpar.pop();
                    }
                    break;
                }else{
                    last  = pqim.top();
                    pqim.pop();
                    act = !act;
                    cnt++;
                }
            }else{
                while(!pqpar.empty() && pqpar.top()<=last){
                    stpr.push(pqpar.top());
                    pqpar.pop();
                }
                if(pqpar.empty()){
                    while (!pqim.empty())
                    {
                        stim.push(pqim.top());
                        pqim.pop();
                    }
                    break;
                }else{
                    last  = pqpar.top();
                    pqpar.pop();
                    act = !act;
                    cnt++;
                }
            }
        }
        while (cnt<n)
        {
            // cout<<last<<" "<<act<<"\n";
            
            if(act){
                // cout<<stim.top()<<"\n";
                if(last<=stim.top()){
                    f = 0;
                    break;
                }else{
                    last = stim.top();
                    stim.pop();
                    cnt++;
                    act= !act;
                }
            }else{
                if(last<=stpr.top()){
                    f = 0;
                    break;
                }else{
                    last = stpr.top();
                    stpr.pop();
                    cnt++;
                    act= !act;
                }
            }
        }
        if(f){
            cout<<"YES\n";
        }else{
            cout<<"NO\n";
        }

    }   
    
    
    

    return 0;
}