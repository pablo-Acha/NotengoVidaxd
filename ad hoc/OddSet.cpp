#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef vector<ll> vll;

int main(){
    int t;cin>>t;
    while (t--)
    {
        int n;cin>>n;
        n *=2; 
        int ip = 0,pa = 0;
        for (int i = 0,a; i < n; i++)
        {
            cin>>a;
            if(a&1){
                ip++;
            }else{
                pa++;
            }   
        }
        cout<<((ip == pa)?"Yes":"No")<<"\n";
    }
    
    
    return 0;
}