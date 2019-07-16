#include<bits/stdc++.h>
#define debug( x) cout <<#x << " = "<< x <<endl;
using namespace std;
int H, n, k ;
const int MAXN = 100;
int dp[50][50][50][2];
int ways( int x, int y , int r , bool isup){
  if( y < 0 || y > n) return 0;
  if( x == 2*n  ) {
    return (r == 0) && (y ==0);
  }
  int &ans = dp[x][y][r][isup];
  if( ans != -1) return ans;
  ans = 0;

  bool cond = (isup && y == k );
  // up
  ans = ways( x+1, y+1,r, true); 
  // down
  ans += ways( x+1, y-1,r - cond,  false); 
  return ans;
}

int main(){
#ifdef LOCAL 
  freopen("in","r",stdin);
#endif
  int r;
 
  while( cin >> n >> r >> k){
    /* debug( n ); debug( k ); debug( r ); */
    memset( dp, -1, sizeof( dp ));
    int w = ways( 0, 0, r,  false);
    cout << w << endl;
  }
  return 0;
}
