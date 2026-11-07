#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef vector<ll> vll;


int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    ll t;cin>>t;
    while(t--){
        ll n;cin>>n;
        vll arr(n);for(auto &a:arr)cin>>a;
        vll sum;
        for (int i = 0; i < n; i++)
        {
            priority_queue<ll> pq;
            if(arr[i]<0){
                while(i<n && arr[i]<0){
                    pq.push(arr[i]);
                    i++;
                }
            }else{
                while(i<n && arr[i]>0){
                    pq.push(arr[i]);
                    i++;
                }
            }
            sum.push_back(pq.top());
            i--;
        }
        ll res = 0;
        for(auto a:sum)res+=a;    
        // cout<<"\n";
        cout<<res<<"\n";
    }

    return 0;
}