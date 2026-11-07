#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef vector<ll> vll;

void impr(vector<ll> &arr){
    for(auto a:arr)cout<<a<<" ";
    cout<<'\n';
}

int main(){
    string s;cin>>s;
    ll res = 0;
    for (int i = 0; i < s.size(); i++)
    {
        int j =i;
        ll aux = 0;
        while(j<s.size() && s[j] == s[i]){
            j++;
            aux++;
        }
        res = max(aux,res);
        i = j-1;
    }
    if(res>=7){
        cout<<"YES"<<"\n";
    }else{
        cout<<"NO"<<"\n";
    }

    return 0;
}