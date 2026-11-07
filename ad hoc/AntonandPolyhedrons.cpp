#include<bits/stdc++.h>
using namespace std;
int main(){
    map<string,int> mp;
    mp["Tetrahedron"] = 4;
    mp["Cube"] = 6;
    mp["Octahedron"] = 8;
    mp["Dodecahedron"] = 12;
    mp["Icosahedron"] = 20;
    int n;cin>>n;
    string s;
    int res = 0;
    for (int i = 0; i < n; i++)
    {
        cin>>s;
        res+= mp[s];
    }
    cout<<res<<"\n";
    return 0;
}