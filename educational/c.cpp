#include<bits/stdc++.h>
using namespace std;
int main(){
    int t;cin>>t;
    while (t--)
    {
        long long a,b,c,m;cin>>a>>b>>c>>m;
        long long ab= m/lcm(a,b);
        long long ac = m/lcm(a,c);
        long long bc = m/lcm(b,c);
        long long abc = m/lcm(lcm(a,b),c);
long long canta = (m/a) - ab - ac + abc;
long long cantb = (m/b) - ab - bc + abc;
long long cantc = (m/c) - ac - bc + abc;

long long ab2 = ab - abc;
long long ac2 = ac - abc;
long long bc2 = bc - abc;

long long resa = canta*6 + (ab2 + ac2)*3 + abc*2;
long long resb = cantb*6 + (ab2 + bc2)*3 + abc*2;
long long resc = cantc*6 + (ac2 + bc2)*3 + abc*2;
        cout<<resa<<" "<<resb<<" "<<resc<<"\n";
    }
    return 0;
}