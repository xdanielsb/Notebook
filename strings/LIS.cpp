#include<bits/stdc++.h>
using namespace std;
/*
 * Complexity Nlog(N) 
 */
vector< int >  getLis( const vector < int > A){
  int n = A.size();
  if( n == 0) return {};
  vector < int > tail ( n, 0);
  vector < int > lis ( n, 1);
  int ans = 1;
  tail[0] = A[0];
  for( int i = 1; i < n ; i++){
    if( A[i] < tail[0] ) {
      tail[0] = A[i];
      lis[i] = 1;
    }else if( A[i] > tail[ ans - 1] ) {
      tail[ ans++ ] = A[i];
      lis[ i ] = ans;
    }else{
      int cp = upper_bound( tail.begin(), 
                            tail.begin()+ans, A[i]) - tail.begin();
      tail[ cp ] = A[i];
      lis[ i] = cp+1;
    }
  }
  return lis;
}

int main(){
  vector < int > A = { 1, 3, 32 ,2 ,78, 9,2};
  getLis( A );
  // 1 2 3  2 4  3 3
  return 0;
}
