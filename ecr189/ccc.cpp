#ifdef NACHIA
#define _GLIBCXX_DEBUG
#else
// disable assert
#define NDEBUG
#endif
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;
using ll = long long;
const ll INF = 1ll << 60;
#define REP(i,n) for(ll i=0; i<ll(n); i++)
template <class T> using V = vector<T>;
template <class A, class B> void chmax(A& l, const B& r){ if(l < r) l = r; }
template <class A, class B> void chmin(A& l, const B& r){ if(r < l) l = r; }

void testcase(){
  ll N; cin >> N;
  string s, t; cin >> s >> t;
  ll dp0 = 0, dp1 = INF;
  auto f = [&](char l, char r){ return l == r ? 0 : 1; };
  REP(i,N){
    ll nx0 = INF, nx1 = INF;
      chmin(nx0, dp0 + f(s[i], t[i]));
      chmin(nx1, dp0);
    if(i != 0){
      chmin(nx0, dp1 + f(s[i], s[i-1]) + f(t[i], t[i-1]));
    }
    swap(dp0, nx0);
    swap(dp1, nx1);
  }
  cout << dp0 << "\n";
}

int main(){
  cin.tie(0)->sync_with_stdio(0);
  ll T; cin >> T; REP(t,T)
  testcase();
  return 0;
}
