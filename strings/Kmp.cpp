#include<bits/stdc++.h>
#define debug(x) cout <<#x << " = " << x << endl
#define rep(i, a, b) for( __typeof(a) i = a; i < b ; i++)

using namespace std;

int* compute(const string &t) {
  int m = t.size();
  int *p = new int[m];
  p[0]= 0;
  rep( i , 1 , m){
    p[i] = p[ i - 1 ]; 
    while( p[i] > 0 && t[i] != t[ p[i] ] ){
      p[i] = p[ p[i] -1 ];
    }
    if( t[i] == t[ p[i] ] ) p[i]++;
  }
 return p; 
}


int match( const string &ne, const string &ha ){
  debug( ne ); debug( ha);
  int m = ne.size(),  n = ha.size();
  int *p = compute( ne  );

  int s = 0;
  rep( i, 0, n){
    while( s > 0 && ha[ i ] != ne[  s ] )
      s = p[ s - 1];
    if( ha[i] == ne[s] ) s++;
    if( s == m) return i - m + 1;
  }
  delete[] p;
  return -1;
}

int main(){
#ifdef LOCAL 
  freopen("in", "r" , stdin);
#endif

  string needle = "abcaby";
  string haystack  = "abcabcabyid";

  cout << match (  needle , haystack ) <<endl;


  return 0;
}
