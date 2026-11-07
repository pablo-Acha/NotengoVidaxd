#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef vector<long long> vll;
void pr(vll &arr){for(auto a:arr)cout<<a<<"\n";cout<<"\n";}
int main(){
    int n;cin>>n;
    vll arr(n);
    ll sum = 0;
    for (int i = 0; i < n; i++)
    {
        cin>>arr[i];
        sum+= arr[i];
    }
    sort(arr.begin(),arr.end());
    sum = sum/2;
    ll acc = 0;
    int res = 0;
    for (int i = n-1; i >=0; i--)
    {
        acc+= arr[i];
        res++;
        if(acc>sum)break;
    }
    cout<<res<<"\n";
    return 0;
}