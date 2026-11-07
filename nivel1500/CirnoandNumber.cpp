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
        string a;
        ll n;cin>>a>>n;
        a = '0'+a;
        vll arr(n);for(auto &a:arr)cin>>a;
        ll act = 0;
        string menor(a.size(),'0'), mayor(a.size(),'0');
        for (int i = 1; i < a.size(); i++)
        {
            auto p = lower_bound(all(arr),a[i]-'0');
            if(p == arr.end()){
                ll j = i-1;
                auto x = upper_bound(all(arr),a[j]-'0');
                while(x==arr.end()){
                    j--;
                    x = upper_bound(all(arr),a[j]-'0');
                }
                mayor[j] = char(*x+'0'); 
                for (j= j+1; j < a.size(); j++)
                {
                    mayor[j] = char(arr[0]+'0');
                }
                break;
            }else if(*p>a[i]-'0'){
                mayor[i] = char(*p+'0');
                for (int j = i+1; j < a.size(); j++)
                {
                    mayor[j] = char(arr[0]+'0');
                }
                break;
            }else{
                mayor[i] = char(*p+'0');
            }
        }
        for (int i = 1; i < a.size(); i++)
        {
            auto p = lower_bound(all(arr),a[i]-'0');
            if(p == arr.end() || (*p >a[i]-'0' && p!=arr.begin())){
                p--;
                menor[i] = char(*p+'0');
                for (int j = i+1; j < a.size(); j++)
                {
                    menor[j] = char(arr[n-1]+'0');
                }
                // cout<<i<<" gg\n";
                break;
            }else if(*p == a[i]-'0'){
                menor[i] = char(*p+'0');
            }else{
                ll j= i-1;
                auto x = lower_bound(all(arr),a[j]-'0');
                // cout<<menor<<"\n";
                while (j>=1 && x==arr.begin())
                {
                    j--;
                    x = lower_bound(all(arr),a[j]-'0');
                }
                if(j < 1){
                    j = 1;
                    menor[j] = '0';
                }else{
                    x--;
                    menor[j] = char(*x+'0');
                }
                for (j= j+1; j < a.size(); j++)
                {
                    menor[j] = char(arr[n-1]+'0');
                }
                break;
            }
        }
        // cout<<mayor<<" "<<a<<" "<<menor<<"\n";
        ll mx = 0,mn = 0,mid = 0;
        for (int i = 0; i < a.size(); i++)
        {
            mx = mx*10 + (mayor[i]-'0');
            mn = mn*10 + (menor[i]-'0');
            mid = mid*10 + (a[i]-'0');
        }
        
        ll res = min(mx-mid, mid-mn);
        if(mn<arr[0]){
            res = mx-mid;
        }
        cout<<res<<"\n";
        
    }

    return 0;
}