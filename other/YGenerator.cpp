#include <bits/stdc++.h>
using namespace std;
int main(){
	#ifdef LOCAL
  	freopen("new.c", "w", stdout);
  #endif 
  srand (time(NULL));

  int numRandom = 1000;
  cout << numRandom <<endl;
  for( int i=1 ; i<=numRandom ; i++)
  	int cant = rand() % 100 +2; 
  return 0;

}
