#include <bits/stdc++.h>
// #include <bits/extc++.h>

using namespace std;
// using namespace __gnu_pbds;

typedef long long ll;
// typedef tree<pair<ll, int>, null_type, less<pair<ll, int>>, rb_tree_tag, tree_order_statistics_node_update> ordered_set_men;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;

#define dbg(x) cout << #x << ": " << x << endl
#define dbg2(x, y) cout << #x << ": " << x << " _ " << #y << ": " << y << endl;
#define dbg3(x, y, z) cout << #x << ": " << x << " _ " << #y << ": " << y << " _ " << #z << ": " << z << endl;
#define nose cout << "??" << endl;
#define RAYA cout << "=============================" << endl;
#define yesno(sww) if(sww){cout<<"YES\n";}else{cout<<"NO\n";}
#define yesnomin(sww) if(sww){cout<<"Yes\n";}else{cout<<"No\n";}

const ll MOD=1000000000ll + 7ll;
const int INF=MOD;

template <typename T>
void printv(T v)
{
    for (auto x : v) cout << x << " ";
    cout << endl;
}

template <typename T>
void printvii(T v)
{
    for(auto [x,y]:v)cout<<"["<<x<<","<<y<<"]";
    cout<<endl;
}

ll __lcm(ll a,ll b)
{
    return (a*b)/__gcd(a,b);
}


void solve()
{
    int n;cin>>n;

    vector<string> mat(2);
    cin>>mat[0]>>mat[1];

    const int INF=1e9;


    vector<vector<int>> dp(2,vector<int>(n+1));

    //parado
    dp[0][1]=(mat[0][0]!=mat[1][0]);

    //echado
    dp[1][1]=INF;



    for(int i=2;i<n+1;i++)
    {
        //parado
        dp[0][i]=min(dp[0][i-1],dp[1][i-1])+(mat[0][i-1]!=mat[1][i-1]);


        //hechado

        dp[1][i]=min(dp[0][i-2],dp[1][i-2])+(mat[0][i-1]!=mat[0][i-2])+(mat[1][i-1]!=mat[1][i-2]);

    }

    // printv(dp[0]);
    // printv(dp[1]);

    int ans=min(dp[0].back(),dp[1].back());
    cout<<ans<<"\n";




}



int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    if (!freopen("input.txt", "r", stdin)) {
    cerr << "Error abriendo input.txt\n";
}
if (!freopen("out.txt", "w", stdout)) {
    cerr << "Error abriendo out.txt\n";
}
    // freopen("input.txt", "r", stdin);
    // freopen("out2.txt", "w", stdout);


    int t = 1;
    cin >> t;
    while (t--)
    solve();
    return 0;
}
