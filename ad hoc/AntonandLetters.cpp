#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef vector<ll> vll;
int main(){
    string x;cin>>x;
    set<char> st;
    if(x[1] == '}'){cout<<0<<"\n";return 0;}
    st.insert(x[1]);
    while(cin>>x){
        st.insert(x[0]);
    }
    cout<<st.size()<<"\n";
    return 0;
}