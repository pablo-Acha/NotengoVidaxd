#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
bool yes(ll i, vector<ll> &v){
    if(v[i] == v[i+1] && v[i+2] == v[i+3] && v[i] == v[i+3])return true;
    return false;
}
int main(){
    int n;cin>>n;
    vector<ll> arr(n),brr;for(auto &a:arr)cin>>a;
    
    for (int i = 0; i < n; i++)
    {
        brr.push_back(arr[i]);
        if(brr.size()>=4){
            if(yes(brr.size()-4,brr)){
                for (size_t i = 0; i < 4; i++)brr.pop_back();
            }
        }
    }
    cout<<brr.size()<<endl;
    
    return 0;
}