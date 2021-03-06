#include<iostream>
using namespace std;
/*
  Generate all unique
  partitions of a given integer
*/

void partitions(int n){
  int p[n];
  int k = 0;
  p[k] = n;

  while (true){
   for( int i =0; i <=k ; i++) cout <<p[i] << " "; 
   cout <<endl;
   int rem_val = 0;
   while (k >= 0 && p[k] == 1){
    rem_val += p[k];
    k--;
   }
   if (k < 0) return;
   p[k]--;
   rem_val++;
   // If rem_val is more, then the sorted order is violated. Divide
   // rem_val in different values of size p[k] and copy these values at
   // different positions after p[k]
   while (rem_val > p[k]){
    p[k+1] = p[k];
    rem_val = rem_val - p[k];
    k++;
   }
   // Copy rem_val to next position and increment position
   p[k+1] = rem_val;
   k++;
  }
}
int main(){
  cout << "All Unique Partitions of 7 \n";
  partitions(7);
  return 0;
}
