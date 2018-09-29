#include<bits/stdc++.h>
using namespace std;
 
// Returns the longest repeating non-overlapping substring
string longestRepeatedSubstring(string str){
    int n = str.length();
    int LCSRe[n+1][n+1];
    // Setting all to 0
    memset(LCSRe, 0, sizeof(LCSRe));
    string res; // To store result
    int res_length  = 0; // To store length of result
 
    // building table in bottom-up manner
    int i, index = 0;
    for (i=1; i<=n; i++){
      for (int j=i+1; j<=n; j++){
        // (j-i) > LCSRe[i-1][j-1] to remove
        if (str[i-1] == str[j-1] &&
          LCSRe[i-1][j-1] < (j - i)){
          LCSRe[i][j] = LCSRe[i-1][j-1] + 1;
          if (LCSRe[i][j] > res_length){
            res_length = LCSRe[i][j];
            index = max(i, index);
          }
        }
        else
          LCSRe[i][j] = 0;
      }
    }
    if (res_length > 0){
  		cout <<  (index  - res_length +1)<<endl;
  	  for (i = index - res_length + 1; i <= index; i++)
          res.push_back(str[i-1]); 
		}
    return res;
}
 
// Driver program to test the above function
int main(){
    string str = "hello,p23puoeouhello,oues";
    cout << longestRepeatedSubstring(str); //hello,
    return 0;
}
