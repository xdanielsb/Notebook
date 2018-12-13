#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
inline ll add ( ll x, ll y){
  return (x%MOD +y%MOD)%MOD;
}
inline ll mul( ll x , ll y){
  return (x%MOD*1LL*y%MOD)%MOD;
}

inline ll fpow( ll x, ll p){ // (x^p)%MOD
  ll res=1LL;
  while( p ){
    if( p & 1){
      res = mul(res,x);
    }
    p >>= 1LL;
    x = mul(x,x);
  }
  return res;
}
