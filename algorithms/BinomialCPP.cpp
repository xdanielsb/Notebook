#include <iostream>
using namespace std;
const int MAXN = 66;
unsigned long long ch[MAXN+5][MAXN+5];
void binomial(int N){
  for (int n = 0; n <= N; ++n)
    ch[n][0] = ch[n][n] = 1;
  for (int n = 1; n <= N; ++n){
    for (int k = 1; k < n; ++k){
      ch[n][k] = ch[n-1][k-1] + ch[n-1][k];
    }
  }
}
int main(){
  binomial(10);
  cout << ch[10][2] << endl;
}
