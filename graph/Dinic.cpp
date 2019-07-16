#include<bits/stdc++.h>
#define debug( x ) cout << #x << " = " << x <<endl;
using namespace std;
/// Complexity: O(|E|*|V|^2)
/// Implementation Notebook UNAL
// Codeforces 1082/G
typedef long long ll;
const int inf = 1e9+17;
struct edge { ll v, cap, inv, flow; };
struct network {
  ll n, s, t;
  vector<ll> lvl;
  vector<vector<edge>> g;
  network(int n) : n(n), lvl(n), g(n) {}
  void add_edge(int u, int v, int c) {
    g[u].push_back({v, c, g[v].size(), 0});
    g[v].push_back({u, 0, g[u].size()-1, c});
  }
  bool bfs() {
    fill(lvl.begin(), lvl.end(), -1);
    queue<int> q;
    lvl[s] = 0;
    for(q.push(s); q.size(); q.pop()) {
      int u = q.front();
      for(auto &e : g[u]) {
        if(e.cap > 0 && lvl[e.v] == -1) {
          lvl[e.v] = lvl[u]+1;
          q.push(e.v);
        }
      }
    }
    return lvl[t] != -1;
  }
  ll dfs(int u, ll nf) {
    if(u == t) return nf;
    ll res = 0;
    for(auto &e : g[u]) {
      if(e.cap > 0 && lvl[e.v] == lvl[u]+1) {
        ll tf = dfs(e.v, min(nf, e.cap));
        res += tf; nf -= tf; e.cap -= tf;
        g[e.v][e.inv].cap += tf;
        g[e.v][e.inv].flow -= tf;
        e.flow += tf;
        if(nf == 0) return res;
      }
    }
    if(!res) lvl[u] = -1;
    return res;
  }
  ll max_flow(int so, int si, ll res = 0) {
    s = so; t = si;
    while(bfs()) res += dfs(s, INT_MAX);
    return res;
  }
};

int main(){
  #ifdef LOCAL
    freopen("un","r",stdin);
#endif
  int n, m, ai, wi;
  while( cin >>n >>m ){
    int nn = n+m+20;
    int s = nn-1, t = nn-2;
    network nt( nn );
    for( int i= 0; i< n; i++){ // weights
      cin >> ai;
      nt.add_edge( i, t, ai);
    }
    int u , v, w;
    ll sum = 0;
    for( int i = 0; i< m; i++){
      cin >> u >> v >> w;
      --u; --v;
      sum += w;
      nt.add_edge( s, i+n , w);
      nt.add_edge( i+n, u, inf);
      nt.add_edge( i+n, v, inf);
    }

    ll maxFlow = nt.max_flow( s, t );
    ll res = sum - maxFlow;
    cout << res << endl;
  }

  return 0;
}
