#include<bits/stdc++.h>
using namespace std;
int main(){
    string s;cin>>s;
    vector<int> arr;
    for (int i = 0; i < s.size(); i++)
    {
        if(s[i]!='+'){
            arr.push_back(s[i]-'0');
        }
    }
    sort(arr.begin(),arr.end());
    cout<<arr[0];
    for (int i = 1; i < arr.size(); i++)
    {
        cout<<"+"<<arr[i];
    }
    cout<<"\n";
    return 0;
}