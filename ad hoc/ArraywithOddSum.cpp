#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef vector<ll> vll;
int main(){
    int t;cin>>t;
    while (t--)
    {
        int n;cin>>n;
        int im = 0,pa = 0;
        for (int i = 0,a; i < n; i++)
        {
            cin>>a;
            if(a&1){
                im++;
            }else{
                pa++;
            }
        }
        if(im>0 &&((im&1) || pa>0)){
            cout<<"YES"<<"\n";
        }else{

            cout<<"NO"<<"\n";
        }
    }
    
    return 0;
}