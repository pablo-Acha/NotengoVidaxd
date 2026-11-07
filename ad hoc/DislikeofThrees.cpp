#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef vector<ll> vll;

int main(){
    int t;cin>>t;
    vll arr;
    int val = 1;
    while(arr.size()<=1000){
        if(!(val%3 == 0 || val%10 == 3)){
            arr.push_back(val);
        }
        val++;
    }
    
    while(t--){
        ll n;cin>>n;
        cout<<arr[n-1]<<"\n";
    }

    
    return 0;
}