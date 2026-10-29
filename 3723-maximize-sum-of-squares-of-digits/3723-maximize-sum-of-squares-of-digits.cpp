class Solution {
public:
    string maxSumOfSquares(int num, int sum) {
        if (num * 9LL < sum) {
            return "";
        }

        int k = sum / 9;
        int s = sum % 9;

        string ans(k, '9');
        if (s > 0) {
            ans += (char)('0' + s);
        }

        ans.append(num - ans.length(), '0');

        return ans;
    }
};