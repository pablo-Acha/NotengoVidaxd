#include<bits/stdc++.h>
using namespace std;
int main(){
    int t;cin>>t;
    while (t--)
    {
        int n;cin>>n;
        string s;cin>>s;
        vector<int> arr(s.size());
        int i = 0;
        int res  = 0;
        while(true){
            if(!arr[i]){
                arr[i] =1;
                res++;
            }else{
                break;
            }
            if(s[i] == 'R'){
                i++;
            }else{
                i--;
            }
        }
        cout<<res<<"\n";
        
    }
    
    return 0;
}