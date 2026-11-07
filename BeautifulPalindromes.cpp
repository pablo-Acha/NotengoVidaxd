#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef vector<ll> vll;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t;cin>>t;
    while(t--){
        int n,m;cin>>n>>m;
        vll freq(n+1);
        vll arr(n);for(auto &a:arr){cin>>a;freq[a]++;}
        for (int i = 1; i <= n && m; i++)
        {
            if(freq[i] == 0){
                arr.push_back(i);
                m--;
            }
        }
        // while(m){
        //     m--;
        //     arr.push_back(arr[arr.size()-3]);
        // }
        vll dist(3);
        set<ll> st;
        ll aux = 2;
        for (int i = arr.size() - 1; i >= 0; i--)
        {
            if(st.size() == 3)break;
            if(st.find(arr[i])==st.end()){
                st.insert(arr[i]);
                dist[aux] = arr[i];
                aux--;
            }
        }
        for (int i = 0; i < m; i++)
        {
            arr.push_back(dist[i%3]);
        }
        
        for (int i = n; i < arr.size(); i++)
        {
            cout<<arr[i]<<" ";
        }
        cout<<"\n";
    }
    
    return 0;
}