#include<bits/stdc++.h>
#define  endl '\n'
#define debug(x) cout << #x << " = " << x <<endl;
#define F first
#define S second
using namespace std;
typedef pair<int, int > ii;
typedef long double ld;

/*
 * caso 1 
 *  si el mayor x de los puntos que van subiendo verticalment {mix} es más grande que el menor x de los 
 *  puntos que van bajando verticalmente {max} entonces no es posible, ejemplos
 * caso 2
 *  si el mayor y de los puntos que van izq {miy} es más grande que el menor y de los 
 *  puntos que van a la der {may} entonces no es posible, ejemplos
 *  
3 *       _ 
2 *  ____| |   los que van subiendo (0,0) ( 2,2 ) mix = 2   2 <= 1 false
1 *  |  ___|   los que van bajando  (3,3) ( 1,1)  max = 1                false
0 *  |_|       los que van a la izq (1,0) ( 3,1)  miy = 1   1 <= 2 true
 *   0 1 2 3   los que van a la der (0,2) ( 2,3)  may = 2

3 *      _ 
2 *   /    |   los que van subiendo (0,0)  mix = 0 
1 *  |  ___|   los que van bajando  (3,3) ( 1,1)  max = 1    0 <= 1 true
0 *  |_|       los que van a la izq (1,0) ( 3,1)  miy = 1 
 *   0 1 2 3   los que van a la der (0,2) ( 2,3)  may = 2    1 <= 2 true 

 */

int const inf = INT_MAX;

bool isPossible( vector<ii > &pt ){
  int s = pt.size();
  int mix = -inf, miy = -inf;
  int maxx = inf, may = inf;
  for( int i= 0; i< s ; i++){
    int j = (i+1) % s;
    if( pt[i].F == pt[j].F){
      // going up?
      if( pt[i].S < pt[j].S) mix = max( mix, pt[i].F);
      else maxx = min( maxx, pt[i].F);
    }else{
      // going right?
      if( pt[i].F < pt[j].F) may = min(may, pt[i].S);
      else  miy = max( miy, pt[i].S);
    }
  }
  return mix <= maxx && miy <= may;
}


int main(){
#ifdef LOCAL 
  freopen("in", "r", stdin);
#endif
  int n, floor = 1;
  while( cin >> n && n ){
    vector< ii >  pt(n);
    for( int i = 0; i < n; i++){
      cin >> pt[i].F >> pt[i].S;
    }
    bool ans = isPossible( pt );
    cout << "Floor #"<< floor++ <<endl;
    if( ans ){
      cout<< "Surveillance is possible.\n";
    }else{
      cout<< "Surveillance is impossible.\n";
    }
    cout << '\n';

  }
  return 0;
}
