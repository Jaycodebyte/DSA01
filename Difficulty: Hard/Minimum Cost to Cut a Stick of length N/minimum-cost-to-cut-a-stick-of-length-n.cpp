class Solution {
  public:
    // Jay
      int minCutCost(int n, vector<int>& cuts) {
        cuts.push_back(0);
        cuts.push_back(n);
        sort(cuts.begin(), cuts.end());
        
        int k = cuts.size();
        vector<vector<int>> dp(k, vector<int>(k, 0));

        for (int len = 2; len < k; len++) {
            for (int i = 0; i + len < k; i++) {
                int j = i + len;
                int best = INT_MAX;
                for (int mid = i + 1; mid < j; mid++) {
                    best = min(best, dp[i][mid] + dp[mid][j] + cuts[j] - cuts[i]);
                }
                dp[i][j] = best;
            }
        }
        return dp[0][k - 1];
    }
};