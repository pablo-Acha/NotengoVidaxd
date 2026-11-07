#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef vector<ll> vll;

int main(){
    double c;cin>>c;
    int n;cin>>n;
    double res = 0;
    for (int i = 0; i < n; i++)
    {
        double a,b;cin>>a>>b;
        res+= a*b*c;    
    }
    cout << fixed << setprecision(7) << res << "\n";
    return 0;
}   