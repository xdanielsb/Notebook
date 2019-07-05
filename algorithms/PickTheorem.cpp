#include <complex>
#define F real()
#define S imag()
typedef complex<int> pt;
// magnitude pt abs(pt)
// square distance norm(pt)
// angle made by the origin arg(pt)
// rotate p 90 degrees anti-clockwise
   // p = p*polar(1.0, PI/2.0);
using namespace std;
/*
 * b boundary point
 * i interior point
 * UVA 10088
 */
double pick(int b, int i){
  return (b/2.0) + i -1;
}
