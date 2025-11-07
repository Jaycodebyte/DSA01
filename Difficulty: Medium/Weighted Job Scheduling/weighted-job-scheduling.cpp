class Solution {
  public:
    //Jay
    int maxProfit(vector<vector<int>> &jobs) {
        int n = jobs.size();
        sort(jobs.begin(), jobs.end(), [](auto &a, auto &b) {
            return a[1] < b[1];
        });

        vector<int> endTimes(n);
        for (int i = 0; i < n; i++) endTimes[i] = jobs[i][1];

        vector<int> dp(n);
        dp[0] = jobs[0][2];

        for (int i = 1; i < n; i++) {
            int incl = jobs[i][2];
            int idx = upper_bound(endTimes.begin(), endTimes.end(), jobs[i][0]) - endTimes.begin() - 1;
            if (idx >= 0) incl += dp[idx];
            dp[i] = max(dp[i - 1], incl);
        }
        return dp[n - 1];
        
    }
};
