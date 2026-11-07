#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef vector<long long> vll;

int main(){
    int t;cin>>t;
    while(t--){
        int n,m;cin>>n>>m;
        vll arr(n),brr(m);
        for(auto &a:arr)cin>>a;
        for(auto &a:brr)cin>>a;
        priority_queue<ll,vector<ll>> a,b;
        for (int i = 0; i < n; i++)
        {
            a.push(arr[i]);
        }
        for(int i = 0;i<m;i++)b.push(brr[i]);
        int in = 1;
        bool win = 1;
        // for (int i = 0; i < m; i++)
        // {
        //     cout<<b.top()<<endl;
        //     if(!b.empty())b.pop();
        // }

        while(true){
            if(in&1){
                auto x = a.top();
                auto y = b.top();
                b.pop();
                if(x<y){
                    b.push(y-x);
                }
            }else{
                auto x = b.top();
                auto y = a.top();
                a.pop();
                if(x<y){
                    a.push(y-x);
                }
            }
            if(a.empty()) break;
            if(b.empty()){win = 0; break;}
            in++;
        }
        if(!win)cout<<"Alice"<<endl;
        else cout<<"Bob"<<endl;

    }
    return 0;
}