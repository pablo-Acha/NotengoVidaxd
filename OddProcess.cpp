#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef vector<ll> vll;

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        vll par,impar;
        for (int i = 0,a; i < n; i++)
        {
            cin>>a;
            if(a&1){
                impar.push_back(a);
            }else{
                par.push_back(a);
            }
        }
        sort(impar.begin(),impar.end());
        sort(par.begin(),par.end());
        ll sum = accumulate(par.begin(),par.end(),0LL);
        if(impar.size())sum+= impar[impar.size()-1];
        ll y = par.size()+(impar.size()>0);
        if(impar.size()== 0){
            for (int i = 0; i < n; i++)
            {
                cout<<0<<" ";
            }
            cout<<"\n";
        }else if(par.size() == 0){
            for (int i = 0; i < n; i++)
            {
                if(i&1)cout<<0<<" ";
                else cout<<impar[impar.size()-1]<<" ";
            }
            cout<<"\n";
        }
        else{
            ll val = impar[impar.size()-1]; 
            for (int i = 1; i <= n; i++)
            {
                if(i>=y){    
                    if((i-par.size())&1){
                        cout<<val<<" ";
                    }else{
                        ll aux = i-par.size();
                        if(aux == impar.size()){
                            cout<<0<<" ";
                        }else{
                            cout<<val-par[0]<<" ";
                        }
                    }
                }else{
                    cout<<val<<" ";
                    val+= par[par.size()-i];
                }
            }
            cout<<"\n";

        }
        
        
    }

    return 0;
}