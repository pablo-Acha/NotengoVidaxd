#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef vector<ll> vll;

int main(){
    int t;cin>>t;
     while(t--){
        long long n, m, a, b;
        cin >> n >> m >> a >> b;    
        long long g = __gcd(n, m);
        if(__gcd(a,n)==1 && __gcd(b,m)==1 && g<=2)
            cout << "YES\n";
        else
            cout << "NO\n";
    }
    return 0;


}