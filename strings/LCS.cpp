#include<bits/stdc++.h>
#define debug(x) cout <<#x << " = " << x <<endl;
using namespace std;
string a, b;
const int MAXN = 5000;
int dp[MAXN][MAXN];
int cnt = 0;

int lcs( int u, int v){
  cnt++;
  if( u == 0 || v == 0 ) return 0;
  int &res = dp[u-1][v-1];
  if( res != -1) return res;
  res = 0;
  if( a[u-1] == b[ v-1] ){
    res =  1+ lcs( u-1, v-1);
  }else{
    res = max( lcs(u, v-1), lcs(u-1, v));
  }
  return res;
}

int main(){
  a= "AGGTAB", b="GXTXAYB";
  memset( dp, -1, sizeof(dp));

  int res = lcs(a.size(), b.size());
  debug( res );
  debug(cnt);
  return 0;
}
