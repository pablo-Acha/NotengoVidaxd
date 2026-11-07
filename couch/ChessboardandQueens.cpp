#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef vector<ll> vll;
typedef  pair<int,int> pii;
typedef  pair<ll,ll> pll;
typedef  vector<int> vi;

#define all(x) (x).begin(), (x).end()

void borrar(set<pair<ll,ll>> &st, vector<pair<ll,ll>> &puntos, ll y, ll x){
    for (int i = 0; i < 8; i++)
    {
        if(st.find({y,i}) != st.end()){
            puntos.emplace_back(y,i);
            st.erase({y,i});
        }
        if(st.find({i,x}) != st.end()){
            puntos.emplace_back(i,x);
            st.erase({i,x});
        }
    }
    // ll mn=min(y,x);
    // ll j = 0;
    // while(y-mn+j <8 && x-mn+j<8){
    //     if(st.find({y-mn+j,x-mn+j}) != st.end()){
    //         puntos.emplace_back(y-mn+j,x-mn+j);
    //         st.erase({y-mn+j,x-mn+j});
    //     }
    //     j++;
    // }   
    // mn = min(7-x,y);
    // while(y-mn+j <8 && x+mn-j>=0){
    //     if(st.find({y-mn+j,x+mn-j}) != st.end()){
    //         puntos.emplace_back(y-mn+j,x+mn-j);
    //         st.erase({y-mn+j,x+mn-j});
    //     }
    //     j++;
    // }
}

ll backTrac(set<pair<ll,ll>> &st,ll reinas){
    if(reinas == 8)return 1;
    ll res = 0;
    for(auto [y,x] :st){
        set<pair<ll,ll>> stt = st;
        vector<pair<ll,ll>> puntos;
        borrar(stt,puntos,y,x);
        res+= backTrac(stt,reinas+1);
        for(auto [yy,xx]: puntos){
            stt.insert({yy,xx});
        }
    }
    return res;
}


int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    set<pair<ll,ll>> st;
    for (int i = 0; i < 8; i++)
    {
        string s;cin>>s;
        for (int j = 0; j < 8; j++)
        {
            if(s[j] == '.')st.emplace(i,j);
        }
    }
    ll res = 0;
    // for(auto [y,x]:st){
    //     cout<<y<<" "<<x<<"\n";
    // }
    for (int i = 0; i < 8; i++)
    {
        if(st.find({0,i}) !=st.end()){
            vector<pair<ll,ll>> puntos;
            borrar(st,puntos,0,i);
            res+= backTrac(st,1);
            for(auto [yy,xx]: puntos){
                st.insert({yy,xx});
            }
        }
    }
    cout<<res<<"\n";

    return 0;
}