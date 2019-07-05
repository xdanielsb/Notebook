#include <bits/stdc++.h>
#define rep(i,j,k) for(int i=j; i<k; i++)
using namespace std;
typedef long long ll;
/*
 * Largest Sum Contiguous Subarray
 * Kadane Algorithm
 * Complexity: O(n)
 * UVA 108
 */
inline ll kadane(ll data[8]){
  ll m1= data[0];
  ll m2 = data[0];
  rep(i, 1, len(data)){
    m2 = max(data[i], data[i] + m2);
    m1 = max(m1, m2);
  }
  return m1;
}
