#include <iostream>
using namespace std;
const int N = 1e5 + 10;
int n, q;
int t[2 * N];

int op( int a, int b){
  return min(a, b);
}
void update(int x, int y) {
  for (t[x += n] = y; x > 1; x >>= 1) {
    t[x >> 1] = op(t[x], t[x ^ 1]);
  }
}
int query(int l, int r) {
  int res = 1e8;
  for (l += n, r += n; l < r; l >>= 1, r >>= 1) {
    if (l & 1) res = op(res, t[l++]);
    if (r & 1) res = op(t[--r], res);
  }
  return res;
}
int main() {
  cin >> n >> q;
  for (int i = 0; i < n; i++) {
    cin >> t[i + n];
  }
  for (int i = n - 1; i > 0; i--) {
    t[i] = op(t[i << 1], t[i << 1 | 1]);
  }
  char qt;
  int l, r;
  while (q--) {
    cin >> qt;
    if (qt == 'q') {
      cin >> l >> r;
      cout << query(l - 1, r) << "\n";
    } else {
      cin >> l >> r;
      update(l - 1, r);
    }
  }
  return 0;
}
