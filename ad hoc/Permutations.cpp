#include<bits/stdc++.h>
using namespace std;
int main(){
    long long n;cin>>n;
    if(n == 2 || n == 3){
        cout<<"NO SOLUTION"<<"\n";
        return 0;
    }else if(n == 1){
        cout<<n<<"\n";
        return 0;
    }else if(n == 4){
        cout<<3<<" "<<1<<" "<<4<<" "<<2<<"\n";
        return 0;
    }
    for (int i = 0,a = n, b = (n-(n/2)-(n&1)); i < n; i++)
    {
        if(i&1){
            cout<<b<<" ";
            b--;
        }else{
            cout<<a<<" ";
            a--;
        }
    }
    
    return 0;
}