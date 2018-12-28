#include<bits/stdc++.h>
#define F first
#define S second
using namespace std;
typedef long long ll;
typedef pair<ll, ll> ii;

ll gcd;

ii extended(ll a, ll b) {
  ll y =0, x =1, xx =0, yy =1;
  while (b){
    ll q = a / b;
    ll t = b;

    b = a%b;
    a = t;
    t = xx;
    xx = x-q*xx;

    x = t;
    t = yy;
    yy = y -q*yy;

    y = t;
  }
  gcd = a;
  // a becomes gcd(a,b);
  return {x,y};
}


int main(){ 
#ifdef LOCAL
  freopen("in","r", stdin);
#endif
  int a, b, c;

  // ax + by = c
  while( cin >> a >> b >> c ){
    ii res = extended( a, b );
    if( c % gcd == 0 ){
      ll x = (c/gcd)*res.F, y = (c/gcd)*res.S;
      cout << x <<  " " <<  y << endl;
    }else{
      // no solution
    }
  }
  return 0;
}
