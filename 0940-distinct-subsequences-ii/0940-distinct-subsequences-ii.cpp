class Solution {
public:
    int distinctSubseqII(string s) {
      const int MOD = 1e9 + 7;
      vector<int> endsCount(26, 0);
      int total = 0;

      for (char ch : s) {
        int idx = ch - 'a';
        int newSubseqs = (1LL * total + 1 - endsCount[idx] + MOD) % MOD;

        total = (total + newSubseqs) % MOD;
        endsCount[idx] = (endsCount[idx] + newSubseqs) % MOD;
      }  

      return total;
    }
};