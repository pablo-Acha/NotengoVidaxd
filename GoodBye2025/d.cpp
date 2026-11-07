#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef vector<ll> vll;

int main(){
    int t;cin>>t;
    while(t--){
        int n,m;cin>>n>>m;
        vll arr(n);for(auto &a:arr)cin>>a;
        if(m>n/2){
            cout<<-1<<endl;
        }else{
            map<ll,ll> mapita;
            for (int i = 0; i < n; i++)
            {
                mapita[arr[i]] = i+1;
            }
            sort(arr.begin(),arr.end());
            vector<pair<ll,ll>> pll;
            if(m == 0){
                ll suma = 0;
                for (int i = 0; i < n-1; i++)
                {
                    suma+= arr[i];
                }
                if(suma<arr[n-1]){
                    cout<<-1<<endl;
                    continue;
                }else{
                    int h = 0;
                    ll mx = arr[n-1];
                    ll acc = 0;
                    while(true){
                        if(acc+arr[h]>=mx)break;
                        pll.push_back({mapita[arr[h]],mapita[arr[n-1]]});
                        acc+=arr[h];
                        h++;
                    }
                    for (int i = h; i < n-1; i++)
                    {
                        pll.push_back({mapita[arr[i]],mapita[arr[i+1]]});   
                    }                    
                }

            }else{
                ll resto = n-m;
                for (int i = 0; i < m; i++)
                {
                    ll val = resto/m;
                    ll ini = val;
                    // cout<<val<<endl;
                    if(i == m-1){
                        val+= resto%m;
                    }
                    for (int j = i*ini; j < (i*ini)+val-1; j++)
                    {
                        // cout<<j<<endl;
                        pll.push_back({mapita[arr[j]], mapita[arr[j+1]]});
                    }
                    // cout<<"-----"<<n-m+i<<"-----"<<arr[n-m+i]<<endl;
                    pll.push_back({ mapita[arr[n-m+i]],mapita[arr[(i*ini)+val-1]]});
                }
                
            }
            cout<<pll.size()<<endl;
            for(auto [x,y]:pll){
                cout<<x<<" "<<y<<endl;
            }
        }
    }
    return 0;
}