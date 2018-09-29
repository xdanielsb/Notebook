#include<bits/stdc++.h>
#define debug(x) cout <<#x << " = " << x << endl
using namespace std;

typedef vector < int > vi;
typedef pair < int , int > ii;


void lis( vi & arr){
  int l = arr.size();
  vi m(l, 1);
  for( int i = 1 ; i < l; i++){
    for( int j = 0 ; j < i ; j++){
      if( arr[j] < arr[i])
      m[i] = max( m[i], m[j]+1);
    }
  }
  for( int &i : m) cout << i << " ";
  cout <<endl;
}
int main(){
#ifdef LOCAL 
  freopen("in", "r", stdin);
#endif

  vector < int > A = { 1, 3, 32 ,2 ,78, 9,2};

  lis ( A );

  return 0;
}
