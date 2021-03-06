#include <bits/stdc++.h>
using namespace std;
const double PI = acos(-1);
#define show(x) cout << #x << " = " << x << endl;
/*
 Complexity O(1)
*/
struct pt {
  double x;
  double y;
  pt (){}
  pt (double _x, double _y){
    x = _x;
    y = _y;
  }
};
inline pt getCenter(pt p1, pt p2, pt p3){
  pt center;
  float m1 = (p2.y - p1.y)/(p2.x - p1.x);
  float m2 = (p3.y - p2.y)/(p3.x - p2.x);
  center.x = ( m1 * m2 * (p1.y - p3.y) + m2 * ( p1.x + p2.x)
                  - m1 * (p2.x + p3.x) )
              / (2 * (m2 - m1) );
  center.y = -1 * (center.x - (p1.x + p2.x) / 2) / m1 +  (p1.y + p2.y) / 2;
  return center;
}

int main(){
  pt p1(1,1), p2(2,4), p3(5,3);
  pt res = getCenter(p1, p2, p3);
  show(res.x)
  show(res.y)
  return 0;
}
