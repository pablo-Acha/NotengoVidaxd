#include<bits/stdc++.h>
using namespace std;
int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t;cin>>t;
    while(t--){
        int n,k;cin>>n>>k;
        unordered_map<long long, long long> mapa; 
        vector<int> arr;
        for (long long i = 0,a; i < n; i++){
            cin>>a;
            mapa[a]++;
        }

        for (auto &a:mapa)
        {
            arr.push_back(a.second);
        }
        if(k== n){
            cout<<1<<"\n";
            continue;
        }
        sort(arr.begin(),arr.end());
        int aux = 0;
        for (int i = 0; i < arr.size(); i++)
        {
            if(k-arr[i]>=0){
                k-= arr[i];
                aux+=1;
            }else{
                break;
            }
        }
        // cout<<aux<<"\n";
        cout<< (arr.size()-aux)<<"\n";
        
    }
 
    return 0;
}