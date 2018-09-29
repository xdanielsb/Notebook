#include<bits/stdc++.h>
#define MAX (int) 1e3
using namespace std;
int v[5] = {60, 100, 120, 30, 5};
int w[5] = {10, 20, 30, 30, 5};

int memo[MAX][MAX];

int knapsack( int n , int W){
  if( n  == 0 || W == 0 ) return 0;
  int &ans = memo[n][W];
  if( ans != -1) return ans;
  if( w[n] > W ) { //not include too heavy
    ans =  knapsack(n-1, W);
  }else{
    //Include
    int a1 = v[n]+ knapsack( n-1, W-w[n] );
    //Not include
    int a2 = knapsack( n -1, W);
    ans =  max(a1, a2); 
  }
  return ans;
}

int main() {
  for( int i = 0; i < MAX; i++)
    for( int j = 0; j < MAX; j++)
      memo[i][j] =  -1;


  cout << knapsack ( 5, 50) << endl;
  return 0;
}
