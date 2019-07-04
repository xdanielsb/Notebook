#include<bits/stdc++.h>
using namespace std;
/*
  Catalan
  also 2n!/((n+1)! n!)
*/
ll C( int n){
  if ( n <= 1 ) return 1;
  ll res = 0;
  for( int i= 0; i < n; i++)
    res += C(i) * C( n -i -1);
  return res;
}
/*
  Super Catalan
*/
ll S( int n ){
  if( n <=2 ) return 1;
  ll res =((6*n-9)*S(n-1)-(n-3)*S(n-2))/n;
  return res;
}
