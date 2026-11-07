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
    while(t--){
        ll b,s;cin>>b>>s;
        deque<ll> arr,brr;
        while (b)
        {
            arr.push_front(b%10);
            brr.push_front(s%10);
            b/=10;
            s/=10;
        }
        ll acc = 0,bcc = 0;
        ll res = 0;
        // for(auto a:brr)cout<<a;
        // cout<<"\n";
        // for(auto a:arr)cout<<a;
        // cout<<"\n";
        for (int i = 0; i < arr.size(); i++)
        {
            acc = acc*10+arr[i];
            bcc = bcc*10+brr[i];
            // cout<<bcc<<"\n"<<acc<<"\n----\n";
            if(bcc-acc == 0){
                acc = bcc = 0;
                res+=2;
            }else if(bcc-acc == 1){
                res++;
            }else{
                break;
            }
        }
        cout<<res<<"\n";
        
    }

    return 0;
}