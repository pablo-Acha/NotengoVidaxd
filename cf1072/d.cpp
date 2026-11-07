#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t;cin>>t;
    vector<vector<ll>> pas(31);
    pas[0].push_back(1);
pas[1].push_back(1);
pas[1].push_back(1);

for (int i = 2; i < 31; i++)
{
    pas[i].push_back(1); 

    for (int j = 1; j < i; j++)
    {
        pas[i].push_back(pas[i-1][j-1] + pas[i-1][j]);
    }

    pas[i].push_back(1); 
}
    // for(auto v:pas){
    //     for(auto a:v)cout<<a<<" ";
    //     cout<<"\n";
    // }
    while(t--){
        ll n,k;cin>>n>>k;
        ll base = 0;
        ll aux = n;
        ll res  = 0;
        while(aux){
            aux/=2;
            base++;
        }
        res  += (base>k);
        base--;
        for (int i = base-1; i >=1; i--)
        {
            int m = pas[i].size();
            for (int j = m-1; j >=0; j--)
            {
                // cout<<"-----"<<i<<"\n";
                if(j+i+1>k){
                    // cout<<i<<" "<<j<<"\n";
                    res+= pas[i][j];
                }
            }
        }
        
        cout<<res<<"\n";


    }    
    return 0;
}