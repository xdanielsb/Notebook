#include<bits/stdc++.h>
#define debug(x) cout <<#x << " = " << x <<endl;
#define F first
#define S second
using namespace std;
typedef long long ll;
typedef pair< int, int> ii;
const int MAXN = 2000+10;
ll Tree[ MAXN*2 ] ;


ll sum( ll l, ll r , ll n){
  l+= n; r+=n;
  ll s = 0;
  for( ; l < r; l >>= 1, r>>= 1){
    if( l & 1 ) s+= Tree[l++];
    if( r & 1 ) s+= Tree[--r];
  }
  return s;
}

void update( ll idx, ll n){
  idx += n;
  Tree[idx]++;
  for( ;idx > 1; idx>>=1){
    Tree[ idx >> 1] = Tree[ idx ] + Tree[ idx ^ 1];
  }
  /* for( int i = 0; i< n; i++)cout << Tree[i+n] << " ";cout <<endl; */
}

int main(){
#ifdef LOCAL
  freopen("in","r",stdin);
#endif
  ll t;
  cin >>t;
  ll n, m, k;
  for( int i =1; i <= t; i++){
    cout << "Test case "<< i <<": ";
    cin >> n >> m >> k;
    vector< ii > vi(k);
    for( int j= 0; j < k; j++){
      cin >> vi[j].F >> vi[j].S;
      vi[j].F--; vi[j].S--;
    }
    sort( vi.begin(), vi.end());
    memset( Tree, 0, sizeof(Tree));
    ll ans =0, s1;
    for( int j = 0; j < k; j++){
      s1 = sum( vi[j].S+1, m+1, m); // how many are there after him (**.S, m]
      /* cout << vi[j].S << " " << m << "  sum = " << s1 <<endl; */
      ans += s1;
      update( vi[j].S, m); // add 1 in that location
    }
    cout <<ans <<endl;
  }
  return 0;
}
