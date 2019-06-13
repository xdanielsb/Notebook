#include <bits/stdc++.h>
#define endl '\n'
#define debug1( x ) cout << #x << " = " <<  x << endl;
#define debug2( x, y) cout <<#x << " = " << x << " , " <<#y << " = " << y <<endl;
#define F first
#define S second
#define PB push_back
#define size( x )   int( ( x ).size( ) )
#define endl '\n'
#define rep(i, a, b) for( __typeof(a) i =(a); i<(b);i++)

using namespace std;
typedef long long ll;
typedef pair<int, int> ii;
typedef vector<int> vi;


const int N = 100;
const int MOD = 1e9+9;
struct matrix {
  int m[N][N], r, c;
  matrix(int r, int c) : r(r), c(c) {
    memset(m, 0, sizeof m);
  }
  matrix operator * (const matrix &o) const {
    matrix ret(r, o.c);
    for(int i = 0; i < r; ++i)
      for(int j = 0; j < o.c; ++j) {
        for(int k = 0; k < c; ++k)
          ret.m[i][j] = (ret.m[i][j] + 1ll*m[i][k]*o.m[k][j]) % MOD;
      }
    return ret;
  }
  void show(){
    rep( i,0 ,r){
      rep( j,0, c){
        cout << m[i][j] <<" ";
      }
      cout <<endl;
    }
  }
};

matrix fastPow( matrix &x, int e){
  matrix res(x.r,x.r);
  rep(i , 0, x.r) res.m[i][i] = 1; // identity
  while( e ){
     if( e % 2){
        res = res*x;
     }
     e /= 2;
     x = x*x;
  }
  return res;
}

int main(){
  ios::sync_with_stdio( false );
  cin.tie( nullptr );
#ifdef LOCAL
  freopen("in", "r" , stdin);
#endif
 
  matrix ma(2,2);
  ma.m[0][0] = 2;
  ma.m[0][1] = 5;
  ma.m[1][0] = 1;
  ma.m[1][1] = 8;
  
  ma.show();

  ma = fastPow( ma, 2);
  ma.show();
  
  return 0;
}
