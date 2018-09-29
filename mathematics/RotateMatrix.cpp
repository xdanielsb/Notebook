#include<bits/stdc++.h>
using namespace std;
#define R 4
#define C 4
int arr[R][C];

void reverseColumns(){
  for (int i=0; i<C; i++)
    for (int j=0,  k=C-1; j<k; j++,k--)
      swap(arr[j][i], arr[k][i]);
}
void transpose() {
  for (int i=0; i<R; i++)
  	for (int j=i; j<C; j++)
      swap(arr[i][j], arr[j][i]);
}
/* anticlockwise rotate matrix by 90 degree*/
void rotate90(){
  transpose();
  reverseColumns();
}

int main() {
  int aux [R][C]=
   { {1, 2, 3, 4},
     {5, 6, 7, 8},
     {9, 10, 11, 12},
     {13, 14, 15, 16}
   };
   rotate90();
   return 0;
}
