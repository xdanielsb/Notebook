#include <iostream>
#define debug(x) cout <<#x << " = " << x <<endl;
using namespace std;
const int N = 1e5 + 10;
int n, q;
int t[2 * N], lazy[2*N];  // limit
int arr[N];


//built the tree O(n)
void built(int l, int r, int node=1){
  if( l > r) return; 
  if( l == r){
    t[node] = arr[l];
    return;
  }
  int mid = (l+r)/2;
  built( l, mid, node<<1);
  built( mid+1, r, node<<1|1);
  t[node] = t[node<<1] + t[node<<1 |1];
}

// query O(lg(n))
int query(int start, int end, int l , int r, int node=1){
  if( r < start || end  < l) return 0;
  if( start >= l && end <= r) return t[ node ];
  int mid = ( start + end) >> 1;
  int lans = query( start, mid, l, r, node<<1);
  int rans = query( mid+1, end, l, r, node<<1|1);
  return lans + rans;
}

// Update a pos O(lg(n))
void update(int start, int end, int idx, int val, int node=1){
  if( start == end){
      arr[ idx ] = val; // change value in the st 
      t[ node ] = val;
      return;
  }
  int mid = (start+ end)>>1;
  if( start <= idx and idx <= mid){
    update( start,mid, idx, val, node*2);
  }else{
    update( mid+1, end, idx, val, node*2+1);
  }
  t[ node ] = t[ node << 1 ] + t[node << 1 |1 ];
}

// Update Range Lazy log(n)
void updateRange( int start, int end, int l, int r, int val, int node =1){
  if( lazy[node] != 0){ //pending update
    t[ node ] += ( end - start +1) * lazy[ node ];
    if( start != end){
      lazy[ node << 1] += lazy[node];
      lazy[ node <<1 |1] += lazy[node];
    } 
    lazy[ node] = 0;
  }
  if( start > end || start >r || end <l ) return;
  if( start >= l && end <= r){// fully in range
    t[ node] += (end - start +1) * val;
    if( start != end){
      lazy[ node<<1] += val;
      lazy[ node<<1|1] += val;
    }
    return;
  }
  int mid = ( start +end ) >> 1;
  updateRange( start, mid, l, r, val, node<<1);
  updateRange( mid+1, end, l, r, val, node<<1|1);
  t[node] = t[ node<<1] + t[node<<1|1];
}

//query lazy
int queryLazy(int start, int end, int l , int r, int node=1){
  if( start > end || start > r || end < l) return 0;
  if( lazy[ node] != 0 ){
    t[node] += (end -start +1) * lazy[ node ];
    if( start != end){
      lazy[node<<1] += lazy[ node];
      lazy[node<<1|1 ] += lazy[node];
    }
    lazy[node] = 0;
  }
  if( start >= l && end <= r) return t[ node ];
  int mid = (start + end) /2;
  int p1 = queryLazy( start, mid, l, r, node<<1);
  int p2 = queryLazy( mid+1, end, l, r, node<<1|1);
  return p1 + p2;
}

int main() {
#ifdef LOCAL
  freopen("SegmentTree.test","r",stdin);
#endif
  cin >> n >> q;
  for (int i = 0; i < n; i++){
    cin >> arr[i];
  }
  built( 0, n-1);
  int l, r, ty,pos , val;
  for (int i = 0; i < q; i++) {
    cin >> ty;
    if( ty == 1){ // query
      cin >> l >> r; l--; r--;
      cout << queryLazy(0, n-1, l, r ) << endl;
      /* cout << query( 0, n-1, l, r) <<endl; */
    }else if( ty == 2){ //update single value  
      cin >> pos >> val; // pos 1 indexed
      pos--;
      update( 0, n-1, pos, val);
    }else if( ty ==3){
      cin >> l >> r >> val;
      l--;r--;
      debug(l); debug( r); debug( val );
      updateRange(0, n-1, l, r, val);
    }
  }
  
  return 0;
}

