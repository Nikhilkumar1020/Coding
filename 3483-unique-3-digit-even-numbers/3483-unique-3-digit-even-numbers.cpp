class Solution {
public:
    int totalNumbers(vector<int>& digits) {
     int freq[10] = {0};
     for (int d : digits) {
        ++freq[d];
     }   

     int count = 0;

     for (int num = 100; num <= 998; num += 2) {
        int d1 = num / 100;
        int d2 = (num / 10) % 10;
        int d3 = num % 10;

        int req[10] = {0};
        ++req[d1];
        ++req[d2];
        ++req[d3];

        if (req[d1] <= freq[d1] && req[d2] <= freq[d2] && req[d3] <= freq[d3]) {
            ++count;
        }
     }

     return count;
    }
};