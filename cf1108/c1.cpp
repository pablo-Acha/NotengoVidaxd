#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef vector<ll> vll;
typedef  pair<int,int> pii;
typedef  pair<ll,ll> pll;
typedef  vector<int> vi;

#define all(x) (x).begin(),(x).end()

const ll MOD=1000000007;
ll pow2[200006];

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    pow2[0]=1;
    for(int i=1;i<=200005;i++){
        pow2[i]=(pow2[i-1]*2)%MOD;
    }

    int t;
    cin>>t;

    while(t--){
        int n;
        cin>>n;
        vll arr(n);
        for(int i=0;i<n;i++)cin>>arr[i];

        int i=0;
        int m=0;
        while(i<n&&arr[i]==-1){
            m++;
            i++;
        }

        ll P=1;
        ll prevVal=-1;
        bool havePrev=false;
        int B=0;

        while(i<n){
            ll v=arr[i];
            int j=i;
            while(j<n&&arr[j]==v)j++;
            int g=j-i;
            P=(P*pow2[g-1])%MOD;

            if(havePrev&&(v-prevVal==1)){
                B++;
            }
            prevVal=v;
            havePrev=true;
            i=j;
        }

        ll ans;
        if(m==0){
            ans=P%MOD;
        }else{
            ans=(P*pow2[m-1])%MOD;
            ans=(ans*((1+B)%MOD))%MOD;
        }

        cout<<ans<<"\n";
    }

    return 0;
}