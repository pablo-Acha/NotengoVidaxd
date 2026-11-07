#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef vector<ll> vll;

ll guas(ll n){return n*(n+1) /2;}
int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    ll t;cin>>t;
    while(t--){
        ll n,x,c;cin>>n>>x>>c;
        string s;cin>>s;
        vll arr(x);
        ll res = 0;
        vll ultima(n);
        ll ul = n;
        for (int i = n - 1; i >= 0; i--)
        {
            if(s[i] == 'I'){
                ul = i;
            }
            ultima[i] = ul;
        }
        ll vacio = 0;
        ll conEspacio = -1;     
        for (int i = 0; i < n; i++)
        {
            if(s[i] == 'E' && conEspacio !=-1){
                ll j = 0;
                if(conEspacio<x){
                    arr[conEspacio]++;res++;
                }



                while(j<x && (arr[j]==0 || arr[j]>=c)){
                    j++;
                }
                if(j<x && arr[j]!=0 && arr[j]<c){arr[j]++;res++;}
            }else if(s[i] == 'I'){
                ll j = 0;
                if(vacio<x){
                    arr[vacio]++;vacio++;res++;
                }
                
                while(j<x && arr[j]!=0){
                    j++;
                }
                if(j<x && arr[j] == 0){arr[j]++;res++;}
            }else{
                ll j = 0;
                if(vacio == x){
                    if(conEspacio<x){
                        arr[conEspacio]++;res++;
                    }
                }else{
                    
                }
                if((conEspacio<x && (ultima[i]-i)<=c-arr[conEspacio] &&)  )


                while(j<x && !(arr[j] == 0 || (ultima[i]-i)<= c-arr[j])){
                    j++;
                }
                if(j<x && (arr[j] == 0 || (ultima[i]-i)<= c-arr[j])){arr[j]++;res++;}
                if(j == x){
                    ll j = 0;
                    while(j<x && (arr[j]==0 || arr[j]>=c)){
                        j++;
                    }
                    if(j<x && arr[j]!=0 && arr[j]<c){arr[j]++;res++;}
                }
            }
        }
        
        cout<<res<<"\n";
    }
    return 0;
}