#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef vector<ll> vll;


int main(){
    ll t;cin>>t;
    while(t--){
        ll n;cin>>n;
        string s;cin>>s;
        string a = "1",b = "1";
        bool f = 0;
        for (int i = 1; i < n; i++)
        {
            if(a[i-1] == '1' && b[i-1] == '0'){
                f = 1;
            }
            if(s[i] == '2')
            {    
                if(f){
                    a.push_back('0');
                    b.push_back('2');
                }else{
                    a.push_back('1');
                    b.push_back('1');

                }
                
            }else if(s[i] == '1'){
                if(f){
                    a.push_back('0');
                    b.push_back('1');
                }else{
                    a.push_back('1');
                    b.push_back('0');

                }
                
            }else{
                a.push_back('0');
                b.push_back('0');
            }
        }
        cout<<a<<"\n"<<b<<"\n";
    }
    
    return 0;
}