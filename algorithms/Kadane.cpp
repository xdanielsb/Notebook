#include <bits/stdc++.h>
#define forn(i,j,k) for(int i=j; i<k; i++)
using namespace std;
typedef long long ll;
/*
 * Largest Sum Contiguous Subarray
 * Kadane Algorithm
 * Complexity: O(n)
 */
inline ll kadane(ll data[8], int size){
  ll m1= data[0];
  ll m2 = data[0];
  forn(i, 1, size){
    m2 = max(data[i], data[i] + m2);
    m1 = max(m1, m2);
  }
  return m1;
}
int main(){
  int size = 8;
  ll data[8] = {-1,2,4,-3,5,2,-5,2};
  ll res = kadane(data, size);
  printf("The max sum that can be done with \n \
    Contiguous elements is: %lld \n", res);
  return 0;
}
