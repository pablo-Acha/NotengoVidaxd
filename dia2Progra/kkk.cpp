#include<bits/stdc++.h>
 
using namespace std;
 
#define INF 1000000000
#define EPS 1e-9
#define MOD 1000000007
#define FOR(i, a, b) for(int i = a; i <= b; i++)
#define RFOR(i, a, b) for(int i = a; i >= b; i--)
#define FORP(i, a, b, c) for(int i = a; i <= b; i += c)
#define RFORP(i, a, b, c) for(int i = a; i >= b; i -= c)
#define F first
#define S second
#define all(x) x.begin(), x.end()
#define sort(x) sort(all(x))
#define sz(x) (int)x.size()
#define pb push_back
#define mp make_pair
#define rv(x) for(auto &i: x) cin >> i
#define includes(x, y) x.find(y) != x.end()
#define fill(x, y) memset(x, y, sizeof(x))
#define mxe(x) *max_element(all(x))
#define mne(x) *min_element(all(x))
 
typedef long long ll;
typedef unsigned long long ull;
typedef unsigned int ui;
 
typedef pair<int, int> ii;
typedef pair<ll, ll> pll;
 
typedef vector<int> vi;
typedef vector<ll> vll;
typedef vector<string> vs;
typedef vector<bool> vb;
 
typedef vector<vi> vvi;
typedef vector<vb> vvb;
typedef vector<ii> vii;
typedef vector<pll> vpll;
 
typedef tuple<int, int, int> iii;
 
int t = 1;
bool multiple = false;
ll respuesta = 0;
 
    struct node
{
    // char currentCharacter;
    // bool endOfWord;
    // bool bifurca;
    ll cantidad = 0;
    map<ll,node*> children;
    
};
 
void insert(node *trie, string &word)
{
    node *currentNode = trie;
    for (int i = 0; i < word.size(); i++)
    {
        int index = word[i] - 'a';
        if (currentNode->children.find(index) == currentNode->children.end())
        {
            // cout<<word[i]<< " aaaaaaa "<< '\n' ;
            // currentNode->bifurca = true;
            currentNode->children[index] = new node();
        }
        // currentNode->cantidad++;
        currentNode = currentNode->children[index];
        
        currentNode->cantidad++;
        // currentNode->cantidad++;
        // currentNode->currentCharacter = word[i];
    }
    // cout<<word<<" "<< currentNode->cantidad;
    // currentNode->endOfWord = true;
}
 
 
 
void DFS(node *u) {
  if (u == nullptr) return;
  stack<node> st;
  st.push(*u);
  while (!st.empty())
  {
    node ni  = st.top();
    st.pop();
    int aux = ni.cantidad;
    if(aux >=2){
      respuesta+= (aux*(aux-1))/2;
    }  
    for(auto [a,b]:ni.children){
      st.push(b);
    }
  }
   
//   int aux = u->cantidad;
//   if(aux >=2){
//     respuesta+= (aux*(aux-1))/2;
//   }
//   // cout << s << endl;
//   for(auto [a,b]:u->children){
//     DFS(&b, s + char('a' + a));
//   }
//   for (int i = 0; i < 26; i++){
//     // if(u->bifurca)respuesta += (u->cantidad*(u->cantidad-1)) /2; 
//     DFS(&u->children[i], s + char('a' + i));
//   }
}
 
 
void solve(){
 
  ll n;cin>>n;
  node* Trie = new node();
  for (ll i = 0; i < n; i++)
  {
    string s; cin>>s;
    insert(Trie,s);
  }
  DFS(Trie);
 
  cout<<respuesta;
  
 
}
 
int main(){
 
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
 
  // freopen("input.txt", "r", stdin);
  // freopen("output.txt", "w", stdout);
 
  if (multiple) cin >> t;
  while(t--) solve();
 
  return 0;
}