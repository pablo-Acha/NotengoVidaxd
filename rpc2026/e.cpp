#include<bits/stdc++.h>
using namespace std;

long long valN(long long n, long long x){
    x++;
    if(x>n){
        long long res = x-((x-n)*2);
        return res;
    }
    return x;
}
int main(){
    int n;cin>>n;
    map<long long, long long> arr;
    long long a;
    pair<long long,long long> mxn = {0,0};
    pair<long long,long long> mxc = {0,0};
    for (int i = 0; i < n; i++)
    {
        cin>>a;
        arr[a]++;
    }
    long long nfin = 0;
    for (int i = 1; i < 401; i++)
    {
        bool f = 1;
        for(auto [val,cant]:arr){
            if(val>(i*2)-2){f= 0;break;}
            if(valN(i,val)<cant){f = 0;break;}
        }
        if(f){
            nfin = i;
            break;
        }
    }
    cout<<nfin<<"\n";
    

    return 0;

}