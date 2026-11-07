#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef vector<ll> vll;
typedef  pair<int,int> pii;
typedef  pair<ll,ll> pll;
typedef  vector<int> vi;

#define all(x) (x).begin(), (x).end()

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    ll t;cin>>t;
    while (t--)
    {
        ll n;cin>>n;
        vll arr(n);for(auto &a:arr)cin>>a;
        ll cnt = 0;
        vll ind;
        for (int i = 0; i < n; i++)
        {
            if(arr[i] == 0){
                cnt++;
                ind.push_back(i);
            }
        }
        if(cnt == 1){
            cout<<"NO\n";
        }else if(cnt>1){
            cout<<"YES\n";
            string s(n,'0');
            s[ind[ind.size()-1]] = 'B';
            ind.pop_back();
            for(auto x:ind){
                s[x] = 'A';
            }
            for (int i = 0; i < s.size(); i++)
            {
                if(s[i] == '0'){
                    s[i] = 'C';
                }
            }
            cout<<s<<"\n";
        }else{
            cout<<"YES\n";
            string s(n,'C');
            cout<<s<<"\n";
        }
    }
    

    return 0;
}