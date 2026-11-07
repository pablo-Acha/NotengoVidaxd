#include<bits/stdc++.h>
using namespace std;
int main(){
    int n;cin>>n;
    for (int i = n+1; i < 10000; i++)
    {
        set<int> val;
        int x = i;
        for (int i = 0; i < 4; i++)
        {
            val.insert(x%10);
            x = x/10;
        }
        if(val.size() == 4){
            cout<<i<<"\n";
            break;
        }
    }
    
    return 0;
}