#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef vector<long long> vll;
void pr(vll &arr){for(auto a:arr)cout<<a<<" ";cout<<"\n";}
int main(){
    string s;cin>>s;
    s = s+"WUB";
    int n = s.size();
    vector<string> ars;
    for (int i = 0; i < n; i++)
    {
        if(s.substr(i,3) == "WUB"){
            i+=2;continue;
        }
        string x = "";
        while (s.substr(i,3) != "WUB")
        {
            x.push_back(s[i]);
            i++;
        }
        i--;
        ars.push_back(x);        
    }
    for(auto a:ars){
        cout<<a<<" ";
    }
    cout<<"\n";
    return 0;
}