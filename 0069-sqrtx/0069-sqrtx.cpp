class Solution {
public:
    int mySqrt(int x) {
     if (x < 2) {
        return x;
     }   

     long long l = 1;
     long long r = x / 2;
     long long ans = 1;

     while (l <= r) {
        long long m = l + (r - l) / 2;

        if (m * m <= x) {
            ans = m;
            l = m + 1;
        } else {
            r = m - 1;
        }
     }

     return ans;
    }
};