    #include<bits/stdc++.h>
    using namespace std;
    typedef long long ll;
    typedef vector<ll> vll;
    int main(){
        ios::sync_with_stdio(false);
        cin.tie(nullptr);
        ll t;cin>>t;
        while(t--){
            int n,q;cin>>n>>q;
            n = 1<<n;
            vll arr(n);for(auto &a:arr)cin>>a;
            vll pre(n+1);
            pre[1] =arr[0];
            for (int i = 1; i < n; i++)
            {
                pre[i+1] = pre[i]^arr[i];
            }
            for (ll i = 0,b,c; i < q; i++)
            {
                cin>>b>>c;
                ll res = 0;
                ll aux = arr[b-1];
                ll mid = n/2;
                ll ini = 1;
                ll fin = n;
                while(ini<fin){
                    mid = (fin+ini )/2;
                    ll iz = pre[mid]^pre[ini-1];
                    ll der = pre[fin]^pre[mid];
                    // cout<<iz<<" "<<der<<"\n";
                    if(b>mid){
                        der = (der^arr[b-1])^c;
                        // cout<<"----"<<iz<<" "<<der<<"\n";

                        if(iz>=der){
                            res+= mid-ini+1;
                        }
                        ini = mid+1;
                    }else{
                        
                        iz = (iz^arr[b-1])^c;
                        // cout<<"----"<<iz<<" "<<der<<"\n";
                        if(der>iz){
                            // cout<<"aaa "<<fin-mid<<"\n";
                            res+= fin-mid;
                        }
                        fin = mid;
                    }
                }
                cout<<res<<"\n";
            }
            

        }
        return 0;
    }