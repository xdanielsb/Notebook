#include<bits/stdc++.h>
#define MAX 35
using namespace std;
typedef unsigned long long ll;

ll dp[MAX];
int vi[MAX];
/*
  Complexity: O(n ^ 2)
*/
ll catalan( int n){
  if ( n <= 1 ) return 1;
  if( vi[n] ) return dp[n];
  vi[n] = 1;
  ll &res = dp[n];
  for( int i= 0; i < n; i++)
    res += catalan(i) * catalan( n -i -1);
  return res;
}
int main(){
  memset( dp, 0, sizeof(dp));
  memset( vi, 0, sizeof(dp));
  for( int i = 1; i < 10; i++)
    cout << catalan( i ) <<endl;
  return 0;
}
