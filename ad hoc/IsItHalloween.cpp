#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef vector<ll> vll;

// int main(){
//     string s,x;cin>>s>>x;
//     if(s == "OCT" && x == "31" || s == "DEC" && x == "25"){
//         cout<<"yup\n";
//     }else{
//         cout<<"nope\n";
//     }
//     return 0;
// }   

int main(){
    int t;cin>>t;
    while (t--)
    {
        ll n;cin>>n;
        if(n>=5){
            cout<<"0\n";
        }else{
            ll res = 1;
            for (int i = 1; i <= n; i++)
            {
                res*=i;
            }
            cout<<res%10<<"\n";
        }
    }
    
}