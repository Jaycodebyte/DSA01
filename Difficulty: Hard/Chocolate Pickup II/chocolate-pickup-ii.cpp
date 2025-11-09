class Solution {
  public:
  //Jay
     int n;
     int dp[51][51][51];
    
    int solve(int r1, int c1, int r2, vector<vector<int>> &mat) {
        int c2 = r1 + c1 - r2;
        
        if (r1 >= n || c1 >= n || r2 >= n || c2 >= n || 
            mat[r1][c1] == -1 || mat[r2][c2] == -1)
            return -1e9;
        
        if (r1 == n-1 && c1 == n-1)
            return mat[r1][c1];
        
        if (dp[r1][c1][r2] != -1)
            return dp[r1][c1][r2];
    
        int chocolates = 0;
        if (r1 == r2 && c1 == c2)
            chocolates = mat[r1][c1];
        else
            chocolates = mat[r1][c1] + mat[r2][c2];
        
        // All ways
        int temp = max({
            solve(r1, c1 + 1, r2, mat),
            solve(r1 + 1, c1, r2, mat),
            solve(r1, c1 + 1, r2 + 1, mat),
            solve(r1 + 1, c1, r2 + 1, mat)
        });
        
        chocolates += temp;
        return dp[r1][c1][r2] = chocolates;
    }
    
    int chocolatePickup(vector<vector<int>> &mat) {
        n = mat.size();
        memset(dp, -1, sizeof(dp));
        
        int ans = solve(0, 0, 0, mat);
        return max(0, ans);
    }
};