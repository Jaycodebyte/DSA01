class Solution {
  public:
     //Jay
     int minCost(vector<vector<int>> &costs) {
        int n = costs.size();
        if (n == 0) return 0;

        int k = costs[0].size();
        if (k == 0) return 0;

        if (k == 1) {
            return (n == 1 ? costs[0][0] : -1);
        }

        vector<long long> dp(k), newdp(k);

        for (int j = 0; j < k; j++) dp[j] = costs[0][j];

        for (int i = 1; i < n; i++) {
            long long min1 = LLONG_MAX, min2 = LLONG_MAX;
            int minIdx = -1;

            for (int j = 0; j < k; j++) {
                if (dp[j] < min1) {
                    min2 = min1;
                    min1 = dp[j];
                    minIdx = j;
                } else if (dp[j] < min2) {
                    min2 = dp[j];
                }
            }

            for (int j = 0; j < k; j++) {
                if (j == minIdx) newdp[j] = costs[i][j] + min2;
                else newdp[j] = costs[i][j] + min1;
            }

            dp = newdp;
        }

        long long ans = *min_element(dp.begin(), dp.end());
        return ans >= LLONG_MAX ? -1 : (int)ans;
        
    }
};