#include<bits/stdc++.h>
#define debug(x) cout << #x << " = " << x <<endl;
#define PB push_back
using namespace std;

typedef vector < bool > vb;
typedef vector < int > vi;

enum { NV, SV, V};
vb vis;
int N;
vector < vi > G;

void dfs( int src, stack < int > &S ){
  for( int son: G[src]){
    if( vis[ son ] == NV)
      dfs( son, S );
  }
  vis[src] = V;
  S.push( src );
}

void tsort( ){
  stack< int > S;
  vis.resize( N );
  vis.assign( N, NV);
  for( int i = 0; i < N; i++){
    if( vis[i]  == NV)   dfs( i, S);
  }
  while(!S.empty()){
    cout << S.top() <<endl;
    S.pop();
  }
}

int main(){

  N = 6;
  G.resize(N);
  G[0].PB( 1 );
  G[0].PB( 2 );
  G[0].PB( 3 );
  G[1].PB( 4 );
  G[4].PB( 3 );
  G[5].PB( 2 );
  G[3].PB( 2 );


  tsort( );

  return 0;
}
