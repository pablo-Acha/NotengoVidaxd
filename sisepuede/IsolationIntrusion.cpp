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

    ll n;cin>>n;
    vll arr(3);
    for (int i = 0; i < 3; i++)
    {
        cin>>arr[i];
    }
    sort(all(arr));
    if(arr[0]+n<arr[1]){
        cout<<arr[0]+n<<"\n";
    }else{
        cout<<"impossible\n";   
    }
    

    return 0;
}