class Solution {
public:
    int reverseDegree(string s) {
      int total = 0;
      int n = s.length();

      for (int i = 0; i < n; ++i) {
        int rank = 'z' - s[i] + 1;
        total += (i + 1) * rank;
      }  

      return total;
    }
};