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
        ll n;cin>>n;
        ll m = n;
        vll arr(n);
        ll j = n-1;
        set<ll> st;
        
        while(j>=0){
            if(n&1){
                if(n == 1){
                    arr[j] = n;
                    st.insert(1);
                    ll aux = 0;
                    for (int i = 3; i <= m; i+=2)
                    {
                        if(st.find(i)== st.end()){aux = i;break;}                        
                    }
                    st.insert(aux);
                    arr[j-1] = aux;
                    j-=2;
                    break;           
                }else if(n == 3){
                    arr[j] = 3;
                    arr[j-1] = 1;
                    arr[j-2] = 2;
                    j-=3;
                    st.insert(3),st.insert(1),st.insert(2);
                    break;
                }else{
                    st.insert(n);
                    arr[j] = n;
                    j--;
                    n--;
                }
            }else{
                ll p = n,s = 0;
                for (int i = 0; i <= 63 && p; i++)
                {
                    if(p%2 == 0){s+=1<<i;} 
                    p/=2;
                }
                st.insert(n);
                arr[j] = n;
                j--;
                n= s;
            }
        }
        ll cnt = m;
        for (int i = j; i >= 0; i--,cnt--)
        {
            while(st.find(cnt) != st.end()){
                cnt--;
            }
            arr[i] = cnt;
        }
        ll p = m,s = 0;
        for (int i = 0; i <= 63 && p; i++)
        {
            if(p%2 == 0){s+=1<<i;} 
            p/=2;
        }
        // cout<<s<<"\n-----";
        ll k = 0;
        for (int i = 0; i < m; i++)
        {
            if((i+1)&1){
                k &=arr[i];
            }else{
                k |=arr[i];
            }
            // cout<<k<<" ";
        }
        // cout<<"\n";
        if(m&1)cout<<m<<"\n";
        else cout<<(s|m)<<"\n";
        // cout<<k<<"\n";
        for(auto a:arr){
            cout<<a<<" ";
        }
        cout<<"\n";
    }
    return 0;
}