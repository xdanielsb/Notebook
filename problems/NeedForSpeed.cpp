#include<bits/stdc++.h>
#define debug(x) cout <<#x << " = " << x << endl;
using namespace std;
typedef long double ld;
const int MAXN = 1005;
int d[ MAXN ];
int v[ MAXN ];
int n;
ld t;



inline ld check(ld mid){
  ld sum = 0;
  for( int i = 0; i< n; i++){
    ld aux = mid+ v[i];
    if( aux < 0) return 1.; 
    ld ti = ld( d[i] ) / (aux );
    sum += ti;
  }
  return sum - t;
}

void find( ld mi ) {
  ld l = -mi, r = 0x3f3f3f3f, mid;
  for( int i = 0; i< 80; i++){
    mid = ( l+ r) /2.0 ;
    ld ck =  check( mid);
    if( ck < 0 ){
      r = mid;
    }else{
      l = mid;
    }
  }
  cout<<setprecision( 18 ) << r << endl;
}


int main(){
#ifdef LOCAL
  freopen("in","r",stdin);
#endif
  while( cin >> n >> t){
    /* cout <<n << " = "; */
    ld mi = 1e18;
    for( int i =0; i < n ; i++){
      cin >> d[i] >> v[i];
      min((ld) d[i], mi);
    }
    find( mi );
  }
  return 0;
}
