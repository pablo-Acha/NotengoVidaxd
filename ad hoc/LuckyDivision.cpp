#include<bits/stdc++.h>
using namespace std;
int main(){
    int n;cin>>n;
    for (int i = 1; i <= n; i++)
    {
        if(n%i == 0){
            int h = i;
            bool f = 0;
            while (h)
            {
                if(h%10!=7 && h%10!=4 ){
                    f = 1;
                    break;   
                }
                h/=10;
            }
            if(f)continue;
            cout<<"YES"<<"\n";
            return 0;
        }
    }
    cout<<"NO"<<"\n";
    
    return 0;
}