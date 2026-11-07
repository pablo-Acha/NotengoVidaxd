#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef vector<ll> vll;

ll guas(ll n) { return n * (n + 1) / 2; }
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    ll t;cin>>t;
    while (t--)
    {
        ll n;cin>>n;
        vll arr(n);for(auto &a:arr)cin>>a;
        ll mx = 0,mn = 0;
        bool f = 1;
        queue<ll> qu;
        vector<pair<ll,ll>> rang(n);
        for (int i = 0; i < n; i++)
        {
            ll up,d;cin>>d>>up;
            rang[i] = {d,up};
            if(!f)continue;
            if(arr[i] == 1){
                mx++;mn++;
            }else if(arr[i] == -1){
                mx++;
            }   
            // cout<<mx<<" "<<mn<<"\n";
            if(mx>up){
                for (int i = 0; i < mx-up; i++)
                {
                    qu.push(0);
                }
            }
            if(mn<d){
                for (int i = 0; i < d-mn; i++)
                {
                    qu.push(1);
                }
            }
            mx = min(up,mx);
            mn = max(d,mn);
            // cout<<mx<<" "<<mn<<"\n";
            if(mn>mx){f = 0;}

        }
        if(!f){
            cout<<-1<<"\n";
            continue;
        }else{
            for (int i = 0; i < n; i++)
            {
                if(arr[i] ==-1){
                    if(!qu.empty()){
                        arr[i] = qu.front();
                        qu.pop();
                    }else{
                        arr[i] = 1;
                    }
                }
                cout<<arr[i]<<" ";
            }
            // bool f = 1;
            // ll aux = 0;
            // for (int i = 0; i < n; i++)
            // {
            //     aux+=arr[i];
            //     if(aux<rang[i].first || aux>rang[i].second){
            //         f = 0;
            //         break;
            //     }
            // }
            // cout<<(f?"si":"no")<<"\n";
            cout<<"\n";
        }  
    }
    
    return 0;
}