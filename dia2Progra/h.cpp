/*
by ivant23
*/
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int,int> ii;
#define pb push_back
#define all(x) x.begin(), x.end()
#define F first
#define S second

const int MOD = 1e9 + 7;
const int INF = 1e9;
//int t = 1;

map<ll,ll> A;
map<ll,ll> Mr;
map<ll,ll> x2;
ll M = 0;




void factPrim(ll y){
  for (int i = 2; i*i <= y; i++)
  {
    ll aux =0;
    while(y%i == 0){
      aux++;
      y/=i;
    }
    if(A.find(i) !=A.end() && A[i]<20){
      A[i] = A[i] *(M-Mr[i]+1)  +aux;
    }else{
      A[i] = aux;
      Mr[i] = M;
    }
    
    
  }
  if(y>1){
        if(A.find(y) !=A.end() && A[y]<20){
          A[y] = A[y] *(M-Mr[y]+1)  +1;
        }else{
          A[y] = 1;
          Mr[y] = M;
        }
    
  }
  
      
  
}


void factPrim2(ll y){
  for (int i = 2; i*i <= y; i++)
  {
    while(y%i == 0){
      x2[i]++;
      y/=i;
    }
    
    
  }
  if(y>1)x2[y]++;
  
}
void solve() {
  ll q; cin>>q;
  
  while(q--){
    
    ll t,x; cin>>t>>x; 
    //cout<<t<<'\n';
    if(t == 1){
      factPrim(x);
      
      continue;
    }
    if(t==2){
      M += x;
      
    
      continue;
    }
    if(t == 3){
      factPrim2(x);
      bool f = 1;
      for(auto [p,can]:x2){
        if(A.find(p)== A.end() || (A[p]< can && M<20)){
          f = 0;
          break;
        }
      }
      x2.clear();
      
      cout<<(f?"Yes\n":"No\n");
    
    }
    
    
    
    
  }
    
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    //if (t > 1) cin >> t;
    //while (t--)
    solve();
    
    return 0;
}