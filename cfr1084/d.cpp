#include<bits/stdc++.h>
using namespace std;
#define rnl "\n"
typedef long long ll;
typedef vector<ll> vll;



int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    ll t;cin>>t;
    while (t--)
    {
        int n,x,y;cin>>n>>x>>y;
        vll arr(n);for(auto &a:arr)cin>>a;
        deque<ll> medio,extre;
        for (int i = 0; i < n; i++)
        {
            if(i>=x && i<y){
                medio.push_back(arr[i]);
            }else{
                extre.push_back(arr[i]);
            }
        }

        if(extre.size() == 0){
            ll mnM = *min_element(medio.begin(),medio.end());
            ll indM = min_element(medio.begin(),medio.end())-medio.begin();
            
            for (int i = 0; i < indM; i++)
            {
                medio.push_back(medio.front());
                medio.pop_front();
            }  
            for(auto a:medio)cout<<a<<" ";
            cout<<"\n";
        }else if(medio.size() == 0){
            for(auto a:extre)cout<<a<<" ";
            cout<<"\n";
        }else{

            ll mnM = *min_element(medio.begin(),medio.end());
            ll indM = min_element(medio.begin(),medio.end())-medio.begin();
            for (int i = 0; i < indM; i++)
            {
                medio.push_back(medio.front());
                medio.pop_front();
            }  
            bool f = 0;
            for (int i = 0; i < extre.size(); i++)
            {
                if(extre[i]>medio[0]){
                    for (int j = 0; j < i; j++)
                    {
                        cout<<extre[j]<<" ";
                    }
                    for (int j = 0; j < medio.size(); j++)
                    {
                        cout<<medio[j]<<" ";
                    }
                    for (int j = i; j < extre.size(); j++)
                    {
                        cout<<extre[j]<<" ";
                    }
                    f = 1;
                    break;
                    
                }
            }
            if(!f){
                for(auto a: extre)cout<<a<<" ";
                for(auto a: medio)cout<<a<<" ";
            }
            cout<<"\n";            
        }
        //         for(auto a:medio)cout<<a<<" ";
        //     cout<<"\n";
        //   for(auto a:extre)cout<<a<<" ";
        //     cout<<"\n";
        
        
    }
    
    return 0;
}