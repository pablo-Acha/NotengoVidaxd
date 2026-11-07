#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int main(){
    int t;cin>>t;
    while(t--){
        ll n,k;cin>>n>>k;
        vector<ll> res(k,n);
        if(k%2==0){
            ll ni = n;
            ll aux = 0;
            ll ibit = 0;
            while (ni)
            {
                ibit++;
                ni = ni>>1;
            }
            ibit--;
            // cout<<ibit<<endl<<"-----------";
            ni = n;
            for (int i = ibit-1; i >=0; i--)
            {
                if((ni>>i) &1){
                    // cout<<endl<<i<<endl;
                    ni = ni ^ (1<<i);
                    aux = 1<<i;
                    // cout<<aux<<" "<<ni<<endl;
                    for (int j = i-1; j >=0 ; j--)
                    {
                        if(((ni>>j) &1)  == 0){
                            // cout<<j<<" "<<ni<<" "<<aux<<endl;
                            ni = ni | (1<<j);
                            aux = aux |(1<<j);
                        }
                    }
                    
                    break;
                }   
            }
            res[k-1] = aux;
            res[k-2] = ni;
            
        }
        for(auto &a:res)cout<<a<<" ";
        cout<<endl;
    }
    return 0;
}