#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int main(){
    int n;cin>>n;
    vector<ll> arr(n),brr(n);
    for (int i = 0; i < n; i++)
    {
        cin>>arr[i];
        brr[i] = arr[i];
    }
    sort(brr.begin(),brr.end());
    vector<pair<int,int>> res;
    for (int i = 0; i < n; i++)
    {
        if(arr[i]!=brr[i]){
            int in = 0;
            for (int j = i+1; j < n; j++)
            {
                if(arr[i]== brr[j] && brr[j]!=arr[j]){
                    swap(arr[i],arr[j]);
                    in = j;
                    res.push_back({i,in});
                    i--;
                    break;
                }
            }
        }
    }
    cout<<res.size()<<"\n";
    for (int i = 0; i < res.size(); i++)
    {
        auto [a,b] = res[i];
        cout<<a<<" "<<b<<"\n";
    }
    

    return 0;
}