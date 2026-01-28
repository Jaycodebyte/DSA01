class Solution {
  public:
  //Jay
     int countSubset(vector<int> &arr, int k) {
        int n = arr.size();
        int mid = n / 2;

        vector<int> left(arr.begin(), arr.begin() + mid);
        vector<int> right(arr.begin() + mid, arr.end());

        vector<long long> sumLeft, sumRight;

        int nL = left.size();
        int nR = right.size();
        
        for (int mask = 0; mask < (1 << nL); mask++) {
            long long s = 0;
            for (int i = 0; i < nL; i++) {
                if (mask & (1 << i))
                    s += left[i];
            }
            sumLeft.push_back(s);
        }

        for (int mask = 0; mask < (1 << nR); mask++) {
            long long s = 0;
            for (int i = 0; i < nR; i++) {
                if (mask & (1 << i))
                    s += right[i];
            }
            sumRight.push_back(s);
        }

        // Store frequencies of right sums
        unordered_map<long long, int> freq;
        for (long long s : sumRight)
            freq[s]++;

        int count = 0;
        for (long long s : sumLeft) {
            long long need = k - s;
            if (freq.count(need))
                count += freq[need];
        }

        return count;
        
    }
};