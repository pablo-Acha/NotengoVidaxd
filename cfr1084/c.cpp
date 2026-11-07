#include<bits/stdc++.h>
using namespace std;
#define rnl "\n"
typedef long long ll;
typedef vector<ll> vll;



int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    ll t;cin>>t;
    while (t--)
    {
        int n;cin>>n;
        string s;cin>>s;
        if(s.size() == 1){
            cout<<"NO"<<"\n";
            continue;
        }
        stack<char> aux;
        aux.push(s[0]); 
        
        for (int i = 1; i < n; i++)
        {
            if(aux.empty()){
                aux.push(s[i]);
                continue;
            }
            if(s[i] == aux.top()){
                aux.pop();
            }else{
                aux.push(s[i]);
            }
        }
        if(aux.empty()){
            cout<<"YES"<<"\n";
        }else{
            cout<<"NO"<<"\n";
        }
        
    }
    
    return 0;
}