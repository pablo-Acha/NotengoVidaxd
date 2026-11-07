#include<bits/stdc++.h>
using namespace std;

int main(){
    int n;cin>>n;
    int i = 1;
    int j = 1;
    while(n>=j){
        n-=j;
        i++;
        j+=i;
    }
    cout<<i-1<<"\n";
    return 0;
}