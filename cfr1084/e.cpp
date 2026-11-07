#include<bits/stdc++.h>
using namespace std;
#define rnl "\n"
typedef long long ll;
typedef vector<ll> vll;

bool esCuadradoPerfecto(long long n) {
    if (n < 0) return false;
    long long r = llround(sqrt(n));
    return r * r == n;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    const int N = 1'000'000;
    vector<bool> is_prime(N + 1, true);
    is_prime[0] = is_prime[1] = false;

    for (int i = 2; i * i <= N; i++) {
        if (is_prime[i]) {
            for (int j = i * i; j <= N; j += i)
                is_prime[j] = false;
        }
    }

    set<int> primos;
    for (int i = 2; i <= N; i++) {
        if (is_prime[i])
            primos.insert(i);
    }
    ll t;cin>>t;
    while (t--)
    {
        ll n;cin>>n;
        vll arr(n);for(auto &a:arr)cin>>a;
        bool f = 0;
        ll mx = 0;
        for (int i = 0; i < n; i++)
        {
            if(mx>arr[i]){
                f = 1;
                break;
            }
            mx = max(arr[i],mx);
        }
        if(f){
            cout<<"Alice"<<"\n";
        }else{
            bool p = 0;
            for (int i = 0; i < ; i++)
            {
                
            }
            
        }
        
    }
    
    return 0;
}