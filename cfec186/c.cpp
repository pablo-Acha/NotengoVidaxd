#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef vector<ll> vll;

int main(){
    int t;cin>>t;
    while(t--){
        int n;cin>>n;
        vll arr(n),brr(n),crr(n);
        for(auto &a:arr)cin>>a;
        for(auto &a:brr)cin>>a;
        for(auto &a:crr)cin>>a;
        ll p = 0,s = 0;
        for (int i = 0; i < n; i++)
        {
            bool f = 1;
            for (int j = 0; j < n &&f; j++)
            {
                if(brr[j]>=crr[(i+j)%n]){
                    f= 0;
                    break;
                }
            }
            s+=f;
        }
        for (int i = 0; i < n; i++)
        {
            bool f = 1;
            for (int j = 0; j < n &&f; j++)
            {
                if(arr[j]>=brr[(i+j)%n]){
                    f= 0;
                    break;
                }
            }
            p+=f;
        }
        cout<<p*s*n<<endl;
    }
}