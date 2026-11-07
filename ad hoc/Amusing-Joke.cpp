#include<bits/stdc++.h>
using namespace std;
int main(){
    string s,c,x;cin>>s>>c>>x;
    map<char,int> mp;
    for(auto a:s){
        mp[a]++;
    }
    for(auto a:c){
        mp[a]++;
    }
    bool f = 1;
    for(auto a:x){
        if(mp.find(a) == mp.end()){
            f = 0;
            break;
        }
        mp[a]--;
        if(mp[a]<0){
            f = 0;
            break;
        }
    }
    for(auto [h,j]:mp){
        if(j!=0){
            f = 0;
            break;
        }
    }
    cout<<(f?"YES":"NO")<<"\n";
    return 0;
}