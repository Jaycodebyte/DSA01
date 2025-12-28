class Solution {
  public:
  //Jay
  bool canMake(vector<int>& ranks, int n, int time) {
        long long total = 0;

        for(int r : ranks) {
            long long val = (long long)(1 + (long long)8 * time / r);
            long long k = (sqrt(val) - 1) / 2;
            total += k;

            if(total >= n) return true;
        }
        return false;
    }

    int minTime(vector<int>& ranks, int n) {
        int low = 0;
        int high = *min_element(ranks.begin(), ranks.end()) * n * (n + 1) / 2;
        int ans = high;

        while(low <= high) {
            int mid = low + (high - low) / 2;

            if(canMake(ranks, n, mid)) {
                ans = mid;
                high = mid - 1;
            } else {
                low = mid + 1;
            }
        }
        return ans;
        
    }
};