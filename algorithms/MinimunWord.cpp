// compute the minimun lexicographical word in linear time, doing rotationsn 
int compute( string &s ){
  int n = size( s );
  s = s+s;
  int mn = 0, i =1, step =0;
  while( i < n && mn + step +1 < n){
    if( s[mn+step] == s[i+step]){
      step++;
    }else if( s[mn+step]  < s[i+step]){
      i = i + step +1;
      step = 0;
    }else{
      mn = max(mn+step+1, i);
      i = mn+1;
      step =0;
    }
  }
  return mn;
}
