#include <bits/stdc++.h>
#define MAXCOINS (10005)
#define MAXVALUE (105)
using namespace std;
typedef vector < int > vi;
int dp[MAXVALUE][MAXCOINS];
vi coins;
//recursive
int ways(int tg, int n){
  if ( 0 == tg) return 1;
  if ( 0 > tg) return 0;
  if ( n <= 0 && tg >0) return 0;
  return ways(tg, n-1) + 
    ways(tg - coins[n -1], n);
}
//by dp
int waysdp(int tg, int n){
  for( int i=0; i< coins.size(); i++) dp[0][i] = 1;
  for(int i = 1 ; i<= tg; i++){
   for (int c = 0; c < n; c++){
      int x =0 , y = 0;
      if(i-coins[c] >= 0) x = dp[i - coins[c]][c];
      if( c >=1) y = dp[i][c-1];
      dp[i][c] = x + y;
		}
	}
  return dp[tg][n-1];
}

int main(){
  coins.insert(coins.end(), {1,3,9,27}); 
  cout <<  ways(47, coins.size()) <<endl;
  cout << waysdp(47, coins.size()) <<endl;
  return 0;
}
