#include <iostream>
#define debug(x) cout <<#x << " = " << x <<endl;
using namespace std;
const int N = 1e5 + 10;
int n, q;
int t[2 * N]; // limit


//built the tree O(n)
void built(){ 
  for (int i = n - 1; i > 0; i--) {
    t[i] = t[i << 1]+ t[i << 1 | 1];
  }
}

// set y at position x O(log(n))
void update(int x, int y) {
  for (t[x += n] = y; x > 1; x >>= 1) {
    t[x >> 1] = t[x]+ t[x ^ 1];
  }
}


//operation on interval [l, r) O(log(n))
int query(int l, int r) {
  int res = 0;
  for (l += n, r += n; l < r; l >>= 1, r >>= 1) {
    if (l & 1) res += t[l++];
    if (r & 1) res += t[--r];
  }
  return res;
}
int main() {
#ifdef LOCAL
  freopen("SegmentTree.test","r",stdin);
#endif
  cin >> n >> q;
  for (int i = 0; i < n; i++) {
    cin >> t[i + n];
  }
  built();
  int l, r, ty,pos , val;
  for (int i = 0; i < q; i++) {
    cin >> ty;
    if( ty == 1){ // query
      cin >> l >> r; l--;
      cout << query( l, r ) << endl;
    }else if( ty == 2){ //update single value  
      cin >> pos >> val; // pos 1 indexed
      pos--;
      update(pos, val);
    }
  }
  
  return 0;
}

