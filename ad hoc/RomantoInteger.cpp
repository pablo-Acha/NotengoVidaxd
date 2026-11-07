#include<bits/stdc++.h>
using namespace std;
int main(){
    string s;cin>>s;
    vector<int> arr(s.size());
    map<char,int> mp;
    mp['I']= 1;
    mp['V']= 5;
    mp['X']= 10;
    mp['L']= 50;
    mp['C']= 100;
    mp['D']= 500;
    mp['M']= 1000;
    string c = "a";
    string x = c.reserve();
    for (int i = s.size() - 1; i >= 0; i--)
    {
        arr[i] = mp[s[i]];
    }
    int res = arr[s.size()-1];
    for (int i = s.size() - 2; i >= 0; i--)
    {
        if(arr[i]<arr[i+1])
        {
            res-=arr[i];
        }else{
            res+=arr[i];
        }


    }
    char x = char(0);
    cout<<res<<"\n";
    return 0;
}