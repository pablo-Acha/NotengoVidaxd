#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef vector<ll> vll;
int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t;cin>>t;
    while(t--)
    {
        int n,k;cin>>n>>k;
        map<ll,ll> mp;
        vll arr(n);
        for(int i = 0;i<n;i++){cin>>arr[i];}
        // sort(arr.begin(),arr.end());
        set<ll> st;
        for (int i = 0; i < n; i++)
        {
            st.insert(arr[i]);
        }
        vll brr;
        for(auto a:st){
            brr.push_back(a);  
        }
        for (int i = 0; i < brr.size(); i++)
        {
            mp[brr[i]] = i;
        }
        // cout<<"a"<<endl;
        vll ver(brr.size()),res;
        bool f = 1;
        for (int i = 0; i < brr.size() && f; i++)
        {
            if(ver[i] == 0){
                res.push_back(brr[i]);
                for (int j = brr[i]; j <=k; j+=brr[i])
                {   
                    if(mp.find(j)==mp.end()){
                        f = 0;
                        break;
                    }else{
                        ver[mp[j]] = 1;
                    }
                }
            }
        }
        if(f){
            cout<<res.size()<<"\n";
            for(auto a:res)cout<<a<<" ";
            cout<<"\n";
        }else{
            cout<<-1<<"\n";
        }
    }
    return 0;
}