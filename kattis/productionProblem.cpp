#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef vector<ll> vll;
typedef  pair<int,int> pii;
typedef  pair<ll,ll> pll;
typedef  vector<int> vi;
typedef vector<double> vdd;

#define all(x) (x).begin(), (x).end()

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    ll m,n;cin>>m>>n;
    vdd mat(m);for(auto &a:mat)cin>>a;
    deque<vdd> cant(n,vdd(m));
    deque<double> pre(n);
    for (int i = 0; i < n; i++)
    {
        vdd arr(m);
        for (int j = 0; j < m; j++)
        {
            cin>>arr[j];
        }
        cant[i] = arr;
        cin>>pre[i]; 
    }
    double res = 0; 
    while(true){
        double mx = 0;
        ll j = 0;
        for (int i = 0; i < cant.size(); i++)
        {
            double sum = 1e9;
            // cout<<"//////////\n";
            // for (int h = 0; h < m; h++)
            // {
            //     cout<<cant[i][h]<<" ";
            // }
            // cout<<"\n//////////\n";

            for (int h = 0; h < m; h++)
            {
                
                if(mat[h]>double(0) && cant[i][h]>double(0)){sum = min(sum,mat[h]*(double(100)/cant[i][h]));}
            }
            // cout<<sum<<"\n-----------\n";
            if(sum< 1e9 && sum *pre[i]>mx){
                j = i;
                mx = sum*pre[i];
                // cout<<mx<<"\nxxxxx\n";
            }

        }
        if(mx){
            res+= mx;
            double sum = 1e9;
            for (int h = 0; h < m; h++)
            {
                if(mat[h]>0 && cant[j][h]>0)sum = min(sum,mat[h]*(double(100)/cant[j][h]));
            }
            for (int i = 0; i < m; i++)
            {
                if(mat[i]>0 && cant[j][i]>0)mat[i]-=sum/(double(100)/cant[j][i]);
            }
            cant.erase(cant.begin()+j);
            pre.erase(pre.begin()+j);
            // cout<<cant.size()<<"\n";
        }else{
            break;
        }

    }
    cout << fixed << setprecision(2) << res << endl;
    return 0;
}