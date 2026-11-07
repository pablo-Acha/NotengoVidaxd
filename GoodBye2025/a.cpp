#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef vector<ll> vll;

int main(){
    int t;cin>>t;
    while(t--){
        string s;cin>>s;
        int Y = 0,N = 0;
        for (int i = 0; i < s.size(); i++)
        {
            Y+= s[i]=='Y';
            N+= s[i]=='N';
        }
        if(Y<=1){
            cout<<"YES"<<endl;
        }else{
            cout<<"NO"<<endl;
        }
    }
    return 0;
}