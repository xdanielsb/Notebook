#include<bits/stdc++.h>
using namespace std;

/*
 Complexity: nlog(n)
*/
  ///          from, to, weight
typedef tuple< int,int,int > edge;
typedef vector < int > vi;
bool customSort(const edge &a,const edge & b){
  return get<2>(a) < get<2>(b);
}
vector< edge > mst( vector< edge > &edges , int n ){
  union_find uf( n );
  vector< edge > res;
  sort( edges.begin(), edges.end(), customSort);
  int f, t , w;
  int tw =0;
  for( const edge &e: edges){
    tie(f, t, w) = e;
    if( uf.unite( f, t ) )res.push_back( e);
  }
  return res;
}
int main(){
#ifdef LOCAL
  freopen("in", "r", stdin);
#endif
  int n, m;
  int f, t , w;
  cin >> n >> m;
  vector< edge > edges( m );
  for( int i = 0 ; i <m ; i++){
    cin >> f >> t >> w;
    edges[i] = make_tuple( f, t, w);
  }
  mst( edges, n );
  return 0;
}
