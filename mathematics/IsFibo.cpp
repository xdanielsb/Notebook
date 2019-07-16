#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
bool isPerfectSquare(long long x){
  ll s = sqrt(x);
  return (s*1LL*s == x);
}
bool isFibonacci(int n){
  return isPerfectSquare(5*n*1LL*n + 4) || isPerfectSquare(5*1LL*n*n - 4);
}
