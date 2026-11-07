#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef vector<ll> vll;
int main(){
    vll arr(4);
    for (int i = 0; i < 4; i++)
    {
        cin>>arr[i];
    }
    int d;cin>>d;
    vll res(d+1);
    for (int i = 0; i < 4; i++)
    {
        for (int j = arr[i]; j <= d; j+=arr[i])
        {
            res[j] = 1;
        }
    }
    int cnt = 0;
    for (int i = 1; i < res.size(); i++)
    {
        cnt+= (res[i] == 0);
    }
    cout<<d-cnt<<"\n";
}
