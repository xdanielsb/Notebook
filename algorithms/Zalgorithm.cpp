#include <bits/stdc++.h>
#define pb push_back
using namespace std;
typedef vector<int> vi;

//Complexity: O(N + M)
vi z_val(string s){
  int n = s.size();
  vi z(n);
  for( int  i = 1, l= 0, r=0; i< n; i++){
    if( i <=r) 
      z[i] = min( r-i+1, z[i-l]);
    while( i+z[i] <n && s[ z[i] ] == s[i +z[i]])
      z[i]++;
    if( i+ z[i] -1 > r) 
      l = i, r = i+z[i] -1;
  }
  return z;
}

int main() {
  string haystack = "abcabc", needle = "abc";
  int n = haystack.size(), m = needle.size();
  vi z = z_val(needle + "#" + haystack);
  for( int i = 0; i < n+m; i ++)
    cout << i << " "<< z[i] <<endl;
  return 0;
}
