#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef vector ll;

int main(){#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef vector<ll> vll;

int main(){
    int t;cin>>t;
    while(t--){
        ll n,c,k;cin>>n>>c>>k;
        vll arr(n);
        for (int i = 0; i < n; i++)
        {
            cin>>arr[i];
        }
        sort(arr.begin(),arr.end())
        for (int i = 0; i < n; i++)
        {
            if(arr[i]<=c){
                ll aux  = c;
                c+= min(k,c-arr[i])+arr[i];
                
                k -= min(k,aux-arr[i]);
            }else{
                break;
            }
        }
        cout<<c<<"\n";

    }
    return 0;
}

    return 0;
}