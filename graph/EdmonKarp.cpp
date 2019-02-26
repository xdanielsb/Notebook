#include<bits/stdc++.h>
#define F first
#define PB push_back
#define S second
#define debug( x ) cout <<#x << " = " << x <<endl;
using namespace std;

typedef pair< int, int > ii;
const int INF = 1e9;
int n;
map< ii, int > w;
unordered_map<int, vector<int>> adj;


int bfs(int s, int t, vector<int>& pt) {
  fill(pt.begin(), pt.end(), -1);
  pt[s] = -2;
  queue<ii> q;
  q.push({s, INF});
  while (!q.empty()) {
    int cur = q.front().F;
    int flow = q.front().S; q.pop();
    for (int next : adj[cur]) {
      if (pt[next] == -1 && w[{cur,next}]) {
        pt[next] = cur;
        int new_flow = min(flow, w[{cur,next}]);
        if (next == t) return new_flow;
        q.push({next, new_flow});
      }
    }
  }
  return 0;
}

int maxflow(int s, int t) {
  int flow = 0;
  vector<int> pt(n);
  int new_flow;
  while (new_flow = bfs(s, t, pt)) {
    flow += new_flow;
    int cur = t;
    while (cur != s) {
      int prev = pt[cur];
      w[{prev,cur}] -= new_flow;
      w[{cur,prev}] += new_flow;
      cur = prev;
    }
  }
  return flow;
}


int main(){
#ifdef LOCAL 
  freopen("in","r",stdin);
#endif
  int from, to, cap, m;
  while( cin >> n >>m ){  

    for( int i= 0; i<m ; i++){
      cin >> from >> to >> cap;
      adj[from].PB( to );
      w[{from, to}] = cap;
    }
    
    int mf = maxflow( 0, 3); // from 1 to 5 maxFlow
    debug( mf );
  }
  return 0;
}
