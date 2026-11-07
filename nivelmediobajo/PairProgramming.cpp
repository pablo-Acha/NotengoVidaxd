#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef vector<ll> vll;


int main(){
    int t;cin>>t;
    while(t--){
        int n,m,k;cin>>k>>n>>m;
        vll arr(n),brr(m);
        for(auto &a:arr)cin>>a;
        for(auto &a:brr)cin>>a;
        ll i = 0, j = 0,h = 0;
        vll su(n+m);
        while(i<n && j<m){
            if(arr[i]<brr[j]){
                su[h] = arr[i];
                i++;
            }else{
                su[h] = brr[j];
                j++;
            }
            h++;
        }
        // for(auto a:su)cout<<a<<" ";
        // cout<<"\n";
        // cout<<i<<"\n";
        // cout<<j<<"\n";
        // cout<<h<<"\n";
        if(i!=n){
            for (int r = i; r < n; r++,h++)
            {
                su[h] = arr[r];
            }    
        }else if(j!=m){
            for (int r = j; r < m; r++,h++)
            {
                su[h] = brr[r];
            }
        }
        bool f = 1;
        for (int i = 0; i < n+m; i++)
        {
            if(su[i] == 0){
                k++;
            }else{
                if(su[i]>k){
                    f = 0;
                    break;
                }
            }
        }
        if(f){
            for(auto a:su){
                cout<<a<<" ";
            }
            cout<<"\n";
        }else{
            cout<<-1<<"\n";
        }
    }    

    return 0;
}