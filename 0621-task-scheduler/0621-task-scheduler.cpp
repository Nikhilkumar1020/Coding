class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) {
     int freq[26] = {0};
     for (char task : tasks) {
        ++freq[task - 'A'];
     }   

     int maxFreq = 0;
     for (int i = 0; i < 26; ++i) {
        if (freq[i] > maxFreq) {
            maxFreq = freq[i];
        }
     }

     int maxCount = 0;
     for (int i = 0; i < 26; ++i) {
        if (freq[i] == maxFreq) {
            ++maxCount;
        }
     }

     int partCount = maxFreq - 1;
     int emptySlots = partCount * (n + 1) + maxCount;

     return max((int)tasks.size(), emptySlots);
    }
};