#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
void valores(string &s,map<string,ll> &mp){
    ll ind = 0;
    while(s[ind]!= ','){
        ind++;
    }
    string a = s.substr(1,ind-1);
    ind++;
    ll n = s.size()-ind;
    string b = s.substr(ind,n-1);
    b = "0"+b;
    mp[b] = stoll(a);
    
    // cout<<a<<" "<<b<<"\n";
}

ll indice(string s){
    ll val = 1;
    for (int i = 1; i < s.size(); i++)
    {
        val *=2;
        val += (s[i] == 'R');
    }
    return val;
}
int main(){
    string s;
    // cout<<s.substr(1,2)<<" ";
    while(cin>>s){
        vector<string> arr;
        arr.push_back(s);
        while(true){
            cin>>s;
            if(s == "()")break;
            arr.push_back(s);
        }
        ll n = arr.size();
        vector<ll> res(550);
        map<string,ll> mp;
        for (ll i = 0; i < n; i++)
        {
            valores(arr[i],mp);
        }
        bool f = 1;
        for(auto [a,b]:mp){
            if(a == "0"){ res[1] = b;continue;}
            if(mp.find(a.substr(0,a.size()-1))==mp.end()){
                f = 0;
                break;
            }
            res[indice(a)] = b;
        }
        if(f){
            for(auto a:res){
                if(a)cout<<a<<" ";
            }
            cout<<"\n";
        }else{
            cout<<"incomplete"<<"\n";
        }
        
    }
    return 0;
}