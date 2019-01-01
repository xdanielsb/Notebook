#include <bits/stdc++.h>
#define pb push_back
using namespace std;
typedef vector<int> vi;

/*
 *  Complexity: O(N + M)
*/
vi z_val(string s){
  int n = s.size(), L =0, R=0;
  vi z(n);
  for( int i = 1; i < n ; i++){
    if( i > R){ // not prefix-substr
      L = R = i;
      while( R < n && s[R-L] == s[R]) R++;
      z[i] = R - L; R--;
    }else {
      int k = i - L;
      //there is no longer prefix start at s[i]
      if( z[k] < R-i+1){
        z[i] = z[k];
      }else{
        L = i;
        while( R < n && s[R-L] == s[R]) R++;
        z[i] = R-L; R--;
      }
    }
  }
  return z;
}

int main() {
  string haystack = "abcabca", needle = "abc";
  int n = haystack.size(), m = needle.size();
  vi z = z_val(needle + "#" + haystack);
  for( int i = 0; i < z.size(); i ++)
    cout << i << " "<< z[i] <<endl;
  return 0;
}
