#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef vector<ll> vll;

int main(){
    int t;cin>>t;
    while (t--)
    {
        int n;cin>>n;
        if(n == 2){
            bool f = 0;
            for (int i = 0,j = 1; i < n; i++,j++)
            {
                cout<<"?"<<" "<<j<<" "<<j+1<<"\n";
                cout.flush();
                ll x;cin>>x;
                if(x){
                    cout<<"! "<<j<<"\n";
                    cout.flush();
                    f= 1;
                    break;
                }
            }
            if(!f){
                cout<<"?"<<" "<<1<<" "<<3<<"\n";
                cout.flush();
                ll x;cin>>x;
                if(x){
                    cout<<"! "<<1<<"\n";
                    cout.flush();
                    f= 1;
                    continue;
                }
                cout<<"! "<<n+2<<"\n";
                cout.flush();
            }
            continue;
        }

        bool f = 0;
        for (int i = 0,j= 1; i < n-1; i++,j++)
        {
            cout<<"?"<<" "<<j<<" "<<j+1<<"\n";
            cout.flush();
            ll x;cin>>x;
            if(x){
                cout<<"! "<<j<<"\n";
                cout.flush();
                f= 1;
                break;
            }
        }
        if(!f){
            cout<<"?"<<" "<<1<<" "<<3<<"\n";
            cout.flush();
            ll x;cin>>x;
            if(x){
                cout<<"! "<<1<<"\n";
                continue;
            }
            cout<<"?"<<" "<<2<<" "<<4<<"\n";
            cout.flush();
            cin>>x;
            if(x){
                cout<<"! "<<2<<"\n";
                continue;
            }
            cout<<"! "<<n+2<<"\n";

        }
        
    }
    
    return 0;
}