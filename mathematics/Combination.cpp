#include<bits/stdc++.h>
using namespace std;

vector< int > com;
int k, n ;

void comb( int off, int ki){
  if( ki == 0 ){
    for( int &c: com) cout << c << " ";
    cout <<endl;
    return;
  }
  for( int i = off; i <= n - ki ; i++){
    com.push_back( i );
    comb( i+1, ki-1);
    com.pop_back();
  }
}

int main(){
  n = 5; k = 3;
  comb( 0, k );

  return 0;
}
