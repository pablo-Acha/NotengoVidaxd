#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef vector<ll> vll;
int main(){
    string s;cin>>s;
    int i = 0,n = s.size();
    while(i<n){

        if(s[i] == '.'){
            cout<<"0";
        }else{
            i++;
            if(s[i] == '.'){
                cout<<"1";
            }else{
                cout<<"2";
            }
        }
        i++;
    }
    cout<<"\n";
    return 0;
}
