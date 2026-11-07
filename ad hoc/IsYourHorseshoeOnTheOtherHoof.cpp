#include<bits/stdc++.h>
using namespace std;
int main(){
    set<int> a;
    for (int i = 0,x; i < 4; i++)
    {
        cin>>x;
        a.insert(x);
    }
    cout<<4-a.size()<<"\n";
    return 0;
}