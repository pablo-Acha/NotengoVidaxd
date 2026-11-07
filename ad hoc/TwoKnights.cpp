#include<bits/stdc++.h>
using namespace std;
int main(){
    long long n;cin>>n;
    long long m = max(n+1LL,7LL);
    vector<long long> arr(m);
    arr[1] = 0;
    arr[2] = 6;
    arr[3] = 28;
    arr[4] = 96;
    arr[5] = 252;
    arr[6] = 550;
    for (long long i = 7; i <= n; i++)
    {
        long long x = (i-2)*4;
        arr[i]= arr[i-2] +(20*((i-2)*(i-2)-2))+((x-16)*((i-2)*(i-2)-4))+(((x+3)*(x+4))/2)-16;
    }

    for (long long i = 1; i <= n; i++)
    {
        cout<<arr[i]<<"\n";
    }
    
    return 0;
}