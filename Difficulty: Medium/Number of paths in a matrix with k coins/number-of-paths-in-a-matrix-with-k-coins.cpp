class Solution {
  public:
  //Jay
    int n, m;
    int dp[101][101][101];

    int solve(vector<vector<int>>& mat, int i, int j, int k) {
        if (i >= n || j >= m || k < 0) return 0;
        if (i == n - 1 && j == m - 1)
            return (k == mat[i][j]) ? 1 : 0;

        if (dp[i][j][k] != -1) return dp[i][j][k];

        int remaining = k - mat[i][j];
        int down = solve(mat, i + 1, j, remaining);
        int right = solve(mat, i, j + 1, remaining);

        return dp[i][j][k] = (down + right);
    }

    int numberOfPath(vector<vector<int>>& mat, int k) {
        n = mat.size();
        m = mat[0].size();
        memset(dp, -1, sizeof(dp));
        return solve(mat, 0, 0, k);
    }
};