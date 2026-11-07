#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef vector<ll> vll;

int main(){
    int t;cin>>t;
    while (t--)
    {
        ll n;cin>>n;
        string s;cin>>s;
        string d = "";
        for (int i = 0; i < n; i++)
        {
            char x = s[i];
            while(i<n &&x == s[i]){
                i++;
            }
            d.push_back(x);
            i--;
        }
        int m = d.size();
        set<int> f;
        bool e = 1;
        for (int i = 0; i < m; i++)
        {
            if(f.find(d[i]) == f.end()){
                f.insert(d[i]);
            }else{
                e = 0;
                break;
            }
        }
        cout<<(e?"YES":"NO")<<"\n";
    }
    
    return 0;
}