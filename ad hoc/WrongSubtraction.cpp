#include<bits/stdc++.h>
using namespace std;
int main(){
    long long n,k;cin>>n>>k;
    long long res = 0;
    for (int i = 0; i < k; i++)
    {
        if(n%10){
            n--;
        }else{
            n = n/10;
        }
    }
    cout<<n<<"\n";
    return 0;
}