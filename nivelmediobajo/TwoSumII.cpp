#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef vector<ll> vll;
const ll MOD = 1e9+7;

ll gaus(ll n){
    return (n*(n+1))/2;
}
vector<int> twoSum(vector<int>& numbers, int target) {
    int n = numbers.size();
    vector<int> res;
    for (int i = 0; i < n-1; i++)
    {
        auto p = lower_bound(numbers.begin()+i+1,numbers.end(),target-numbers[i]);
        if(*p+numbers[i] == target){
            res.push_back(numbers[i]);
            res.push_back(*p);
            return res;
        }
    }
    
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    ll n;cin>>n;
    vll arr(n);for(auto &a:arr)cin>>a;
    sort(arr.begin(),arr.end());
    ll ac = 0;
    bool f = 1;
    for (int i = 0; i < n; i++)
    {
        if(arr[i]>ac+1){
            break;
        }else{
            ac +=arr[i]; 
        }
    }
    cout<<ac+1<<"\n";
}