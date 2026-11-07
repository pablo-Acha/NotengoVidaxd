#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef vector<long long> vll;

int main(){
    int t;cin>>t;
    
    while(t--){
        int n,k;cin>>n>>k;
        vll freq(n+1);
        vll arr(n);for(auto &a:arr){cin>>a;freq[a]++;}
        ll res = 0;
        for (int i = 0; i < k-1; i++)
        {
            if(freq[i]>0)res++;
            else break;
        }
        cout<<res<<endl;        
    }
    return 0;
}