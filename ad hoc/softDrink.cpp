#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef vector<ll> vll;
int main(){
    int a,b,c,d,e,f,g,h;cin>>a>>b>>c>>d>>e>>f>>g>>h;
    int x = (b*c)/g;
    int y = (d*e);
    int z = f/h;
    int res = min(min(x,y),z);
    cout<<res/a<<"\n";
}
