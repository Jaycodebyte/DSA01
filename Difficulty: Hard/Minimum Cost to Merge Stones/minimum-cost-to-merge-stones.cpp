class Solution {
  public:
   //Jay
   int mergeStones(vector<int> &stones, int k) {
        int n = stones.size();
        if ((n - 1) % (k - 1) != 0) return-1;

        vector<int> prefix(n + 1, 0);
        for (int i = 0; i < n; i++) prefix[i + 1] = prefix[i] + stones[i];

        vector<vector<vector<int>>> dp(
            n, vector<vector<int>>(n, vector<int>(k + 1, -1))
        );

        function<int(int,int,int)> solve = [&](int i, int j, int piles) -> int {
            if (dp[i][j][piles] != -1) return dp[i][j][piles];
            if (i == j) return dp[i][j][piles] = (piles == 1 ? 0 : 1e9);

            if (piles == 1) {
                int res = solve(i, j, k);
                res += prefix[j + 1] - prefix[i];
                return dp[i][j][piles] = res;
            }

            int ans = 1e9;
            for (int mid = i; mid < j; mid += (k - 1)) {
                ans = min(ans, solve(i, mid, 1) + solve(mid + 1, j, piles - 1));
            }
            return dp[i][j][piles] = ans;
        };

        return solve(0, n - 1, 1);
        
    }
};