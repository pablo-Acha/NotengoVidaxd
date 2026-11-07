    #include<bits/stdc++.h>
    using namespace std;
    typedef long long ll;
    typedef vector<ll> vll;
    int main(){
        ios::sync_with_stdio(false);
        cin.tie(nullptr);
        ll t;cin>>t;
        while(t--){
            ll n,m,k;cin>>n>>m>>k;
            vll arr(n);for(auto &a:arr)cin>>a;
            vll brr(m);for(auto &a:brr)cin>>a;
            string s;cin>>s;
            map<ll,ll> mp;
            ll val = 0;
            for (int i = 0; i < k; i++)
            {
                if(s[i] == 'L'){
                    val-=1;
                }else{
                    val+=1;
                }
                
                if(mp.find(val)==mp.end()){
                    mp[val] = i;
                }
            }
            vll res(k);
            sort(brr.begin(),brr.end());
            for (int i = 0; i < arr.size(); i++) {
                int x = arr[i];
                ll val1 = 0,val2 = 0;
                auto mayor = upper_bound(brr.begin(), brr.end(), x);
                if (mayor != brr.end()){
                    val1 = *mayor -arr[i];
                }

                
                 auto menor = lower_bound(brr.begin(), brr.end(), x);

                if (menor != brr.begin()) {
                    menor--;
                    val2 = *menor -arr[i];
                }
                if(val1 && val2){
                    if(mp.find(val1)!=mp.end() && mp.find(val2)!=mp.end()){
                        ll mn = min(mp[val1],mp[val2]); 
                        res[mn]++;
                    }else if(mp.find(val1)!=mp.end()){
                        res[mp[val1]]++;
                    }else if(mp.find(val2)!=mp.end()){
                        res[mp[val2]]++;
                    }
                }else if(val1){
                    if(mp.find(val1)!=mp.end()){
                        res[mp[val1]]++;
                    } 
                }else if(val2){
                    if(mp.find(val2)!=mp.end()){
                        res[mp[val2]]++;
                    }
                }
            } 
            ll vivos = n;
            for (int i = 0; i < k; i++)
            {
                vivos-= res[i];
                cout<<vivos<<" ";
            }
            cout<<"\n";

        }
        return 0;
    }