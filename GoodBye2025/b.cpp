#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef vector<ll> vll;

int main(){
    int t;cin>>t;
    while(t--){
        string s;cin>>s;
        int n = s.size();
        int res = 0;
        for (int i = 1; i < n-1; i++)
        {
            if(s[i] == 'u'){
                if(s[i-1] == 'u'){
                    s[i-1]= 's';
                    res++;
                }
                if(s[i+1] == 'u'){
                    s[i+1]= 's';
                    res++;
                }
            }
        } 
        if(s[0] == 'u')res++;
        if(s[n-1] == 'u')res++;

        cout<<res<<endl;
    }
    return 0;
}