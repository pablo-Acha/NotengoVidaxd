
/*
by ivant23

Se vuelve mas facil
cada dia es un poco mas facil
pero tienes que hacerlo cada dia es la parte dificil
pero se vuelve mas facil
*/
#include<bits/stdc++.h>

using namespace std;
#define dbg(x) cerr << #x << '=' << (x) << '\n'
#define all(x) (x).begin(), (x).end()
typedef long long ll;

struct LCA {
  int n, LOG;
  vector<int> depth;
  vector<vector<int>> up;

  LCA(const vector<vector<int>>& adj, int root = 0) {
    n = adj.size();
    LOG = 1;
    while ((1LL << LOG) <= n) LOG++;

    depth.assign(n, 0);
    up.assign(n, vector<int>(LOG));

    dfs(root, root, adj);

    for (int j = 1; j < LOG; j++) {
      for (int v = 0; v < n; v++) {
        up[v][j] = up[up[v][j - 1]][j - 1];
      }
    }
  }

  void dfs(int v, int p, const vector<vector<int>>& adj) {
    up[v][0] = p;

    for (int u : adj[v]) {
      if (u == p) continue;
      depth[u] = depth[v] + 1;
      dfs(u, v, adj);
    }
  }

  int query(int a, int b) {
    if (depth[a] < depth[b]) swap(a, b);

    int diff = depth[a] - depth[b];

    for (int j = LOG - 1; j >= 0; j--) {
      if ((diff >> j) & 1) {
        a = up[a][j];
      }
    }

    if (a == b) return a;

    for (int j = LOG - 1; j >= 0; j--) {
      if (up[a][j] != up[b][j]) {
        a = up[a][j];
        b = up[b][j];
      }
    }

    return up[a][0];
  }
};

pair<vector<int>, int> bfs(vector<vector<int>> &grafo, int source) {
  
  int n = grafo.size();
  vector<int> dist(n, -1);
  queue<int> q;
  q.push(source);
  dist[source] = 1;

  while (!q.empty()) {
    int u = q.front(); q.pop();
    for (int v: grafo[u]){
      if (dist[v] == -1) {
        dist[v] = dist[u] + 1;
        q.push(v);
      }
    }
  }
  int mx = *max_element(dist.begin(), dist.end());
  return {dist, mx};
}

int main() {

  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  int n; cin >> n;
  vector<ll> soldiers(n);
  for (int i = 1; i < n; i++) cin >> soldiers[i];
  
  vector<vector<int>> grafo(n, vector<int>());
  for (int i = 0; i < n - 1; i++) {
    int u, v; cin >> u >> v;
    --u,--v;
    grafo[u].push_back(v);
    grafo[v].push_back(u);
  }
  
  LCA lca(grafo);

  ll mxsoldiers = 0;
  int reslvl = 1e9;
  for (int source: grafo[0]){
    auto [levelOfNode, mx] = bfs(grafo, source);

    vector<ll> soldiersAtLevel(mx + 1); //soldados en el nivel i
    for (int i = 0; i < n; i++) {
      soldiersAtLevel[levelOfNode[i]] += soldiers[i];
    }

    vector<int> levelWithMaxSoldiers;
    ll idx = *max_element(soldiersAtLevel.begin(), soldiersAtLevel.end());
    mxsoldiers = max(mxsoldiers, idx);
    for (int i = 0; i < mx + 1; i++) {
      if (soldiersAtLevel[i] == idx) levelWithMaxSoldiers.push_back(i);
    }

    for (int e: levelWithMaxSoldiers) {
      vector<int> nodes; // nodos en el nivel con mas soldados
      for (int i = 1; i < n; i++) {
        if (levelOfNode[i] == e) nodes.push_back(i);
      }
      // for (int e: nodes) cout << e << ' '; //debug
      int res = nodes[0];
      for (int i = 1; i < nodes.size(); i++) { // buscamos el lca de todos los nodos en ese nivel
        res = lca.query(res, nodes[i]);
      }
      // dbg(nodes[0]);
      res = levelOfNode[res]; // obtenemos el nivel del nodo lca
      int height = levelOfNode[nodes[0]] - res + 1;
      reslvl = min(reslvl, height);
    }
  }

  cout << mxsoldiers << ' ' << reslvl << '\n'; // la formula convierte el nivel a 'turno'

  return 0;
}
