#include <iostream>
using namespace std;
typedef long long ll;
ll Horner( ll a[], ll n, ll x ){
  ll result = a[n];
  for(ll i=n-1; i >= 0 ; --i)
    result = result * x + a[i];
  return result;
}
int main(){
  int n = 4;
          //-1 -2x -6x^2 +2x^3
  ll a[] = {-1,-2,-6,2};
  ll x = 8;
  cout << Horner (a, n-1, x);
  return 0;
}
