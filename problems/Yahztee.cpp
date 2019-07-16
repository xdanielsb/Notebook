#include<bits/stdc++.h>
#define debug(x) cout <<#x << " = " << x <<endl;
using namespace std;

int m[13][5];

int d[13][13]; 

/*
 
  d[0][j] value of the first dice thrown with j category
  the categories are given in the problem
  1st category : sum of all ones
  ...

 */
int dp[1<<13];

int nRepeated(int r, int t){
  int cnt[7];
  for( int i= 0; i<=7; i++ ) cnt[i] = 0;
  for( int i =0; i<5;i++) cnt[ m[r][i]]++;
  for( int i =1; i<=7;i++){
    cout << r << " " << i <<  " "<< cnt[i ] <<endl;
    if( cnt[ i] >= t)return true;
  }
  return false;
}
bool fullHouse( int r){
  set <int> s;
  for( int i =0; i < 5; i++) s.insert( m[r][i]);
  return s.size() == 2;
}
bool longStraigth( int r){
  for( int i =0; i< 5;i++){
    if( m[r][i] != (i+1))break;
    if( i== 4) return true;
  }
  for( int i =0; i< 5;i++){
    if( m[r][i] != (i+2))break;
    if( i== 4) return true;
  }
  return false;
}
bool shortStraigth( int r){
  for( int i =0; i< 3;i++){
    if( m[r][i]+1 != m[r][i+1])break;
    if( i == 2) return true;
  }
  for( int i =1; i<= 3;i++){
    if( m[r][i]+1 != m[r][i+1]) break;
    if( i == 3) return true;
  }
  return false;
}
int sum( int r, int j){
  int s =0;
  for( int i =0; i< 5; i++) if( m[r][i] == j) s+=j;
  return s;
}
int sumall( int r){
  int s =0;
  for( int i =0; i< 5; i++)  s+=m[r][i];
  return s;
}

/*
 * mask --> check with cols have already been choosen
 * r --> current rows, stands out the number of the dice thrown
 * sum --> sum of the path
 */
int find(int k,  int cat){
  if( k < 0 ) return 0;
  int &prev = dp[cat];
  if( prev != -1) return prev;

  int ans = 0;
  for( int i = 0; i < 13; i++){
    if(cat&(1<<i)){
      int sum = d[ i ][ k];
      if( ans <  sum + find(k-1, cat - (1 << i))){
        ans =  sum + find(k-1, cat - (1 << i));
      }
    }
  }
  if( k== 5 && ans >= 63 ) ans += 35; 
  return dp[cat] = ans;
}

int main(){
#ifdef LOCAL
  freopen("in","r",stdin);
#endif
  while( cin >> m[0][0]){
    memset( dp, -1, sizeof(dp));
    memset( d, 0, sizeof(d));
    for( int i= 1; i <= 4; i++) cin >> m[0][i];
    
    for( int r =1; r<= 12;r++)
      for( int c =0; c <5;c++)
        cin >> m[r][c];
    
    // create matrix with value
    for( int i =0; i < 13; i++){
      // 1 to 6 sums
      for( int j= 0; j <= 5; j++) d[i][j] = sum(i, j+1); 
      
      // sum all values
      d[i][6] = sumall(i);

      // repeated 3, 4, 5
      for( int j =3, k=0; j<=5; j++,k++)
        if( nRepeated( i, j))
          d[i][7+k] = j < 5? sumall(i): 50;
      
      //straight (short, long) and full house
      if( shortStraigth( i )) d[i][10] = 25;
      if( longStraigth( i)) d[i][11] = 35;
      if( fullHouse( i )) d[i][12] = 40;
    }

    // display matrix for testing purposes
    for( int i =0; i< 13; i++){
      for( int j =0; j < 13;j++)
        cout<< d[i][j] << " ";
      cout << endl;
    }
    cout <<endl;

    cout << find(12, (1<<13)-1) <<endl;

    // print dp
    for( int i= 0; i < 13; i++){
      for( int j = 0; j < ( 1<<13 )-1 ; j++){
        /* cout << dp[i][j] << " "; */
      }
      /* cout <<endl; */
    }
  }

  return 0;
}
