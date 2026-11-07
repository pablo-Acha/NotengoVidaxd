#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef vector<ll> vll;

int main(){
    int t;cin>>t;
    while(t--){
        int n;cin>>n;

        vll arr(n);for(auto &a:arr)cin>>a;
        vll res(n);
        for (int i = 0; i <n; i++)
        {
            int menos = 0;
            int mas = 0;
            for (int j = i+1; j < n; j++)
            {
                if(arr[j]<arr[i])menos++;
                else if(arr[j]>arr[i])mas++;
            }
            res[i] = max(mas,menos);
        }
        for(auto a:res){
            cout<<a<<" ";
        }
        cout<<"\n";
    }
    return 0;
}