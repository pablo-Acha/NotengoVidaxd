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
        bool f =1;
        bool eq = 1;
        for (int i = 1; i < n; i++)
        {
            if(arr[i] != arr[i-1]){
                eq = 0;           
            }else if(abs(arr[i]-arr[i-1])>1){
                f = 0;
                break;
            }
        }
        if(!f){
            cout<<"0\n";
        }else if(eq){
            if(n&1){
                cout<<(arr[0] == n/2 +1?2:0)<<"\n";
            }else{
                cout<<(arr[0] == n/2 +1 || arr[0] == n/2?1:0)<<"\n";
            }     
        }else{
            vll de(n);
            for (int i = 1; i < n; i++)
            {
                if(arr[i]-arr[i-1]>0){
                    if(de[i-1] == 1){f = 0;break;}
                    de[i] = de[i-1] = -1;
                }else if(arr[i]-arr[i-1]<0){
                    if(de[i-1] == -1){f = 0;break;}
                    de[i] = de[i-1] = 1;
                }else{
                    if(de[i-1]!=0){
                        de[i] = de[i-1]*-1;
                    }
                }
            }
            if(!f){
                cout<<"0\n";
                continue;
            }
            for (int i = n - 2; i >= 0; i--)
            {
                if(de[i] !=0)continue;
                de[i] = de[i+1]*-1;
            }
            vll res(n,1);
            ll acc = 0;
            for (int i = 0; i < n; i++)
            {
                res[i] += acc;
                if(de[i] == -1)acc++;
            }
            acc = 0;
            for (int i = n - 1; i >= 0; i--)
            {
                res[i] += acc;
                if(de[i] == 1) acc++;
            }
            cout<<(arr== res)<<"\n";
            
        }
        
    }
    

    return 0;
}