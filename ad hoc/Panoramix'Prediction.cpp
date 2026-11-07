#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef vector<ll> vll;
int main(){
    int n,m;cin>>n>>m;
    bool f = 1;
    for (int j = n+1; j <= m; j++)
    {
        bool fp = 1;
        for (int i = 2; i < j; i++)
        {
            if(j%i == 0){
                fp = 0;
                break;
            }
        }
        if(fp && j < m){
            f = 0;
            break;
        }
        if(j == m){
           f = fp; 
        }
    }
    

    cout<<(f?"YES":"NO")<<"\n";
}
