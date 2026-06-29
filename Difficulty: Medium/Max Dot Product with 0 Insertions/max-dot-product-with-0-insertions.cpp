class Solution {
  public:
  //Jay
   int maxDotProductMemo(int i, int j, int diff, vector<int> &a, vector<int> &b, vector<vector<int>> &dp) {
    //  Base Case
    if(i >= a.size() || j >= b.size()) {
        return 0;
    }
    if(dp[i][j] != -1) {
        return dp[i][j];
    }
    
    // Skipping or multiplying with zero
    int exclude = 0;
    
    if(i - j < diff) {
        exclude = maxDotProductMemo(i+1, j, diff, a, b, dp);
    }
    
    // Adding to dot product
    int include = (a[i] * b[j]) + maxDotProductMemo(i+1, j+1, diff, a, b, dp);
    
    return dp[i][j] = max(include, exclude);
}

// Tabulation
int maxDotProductTab(vector<int> &a, vector<int> &b) {
    int sizeA = a.size();
    int sizeB = b.size();
    int diff = sizeA - sizeB;
    vector<vector<int>> dp(sizeA+1, vector<int>(sizeB+1, 0));
    
    for(int i = sizeA-1; i >= 0; i--) {
        for(int j = sizeB-1; j >= 0; j--) {
            // Skipping or multiplying with zero
            int exclude = 0;
            
            if(i - j < diff) {
                exclude = dp[i+1][j];
            }
            
            // Adding to dot product
            int include = (a[i] * b[j]) + dp[i+1][j+1];
            
            dp[i][j] = max(include, exclude);
        }
    }
    
    return dp[0][0];
}

int maxDotProduct(vector<int> &a, vector<int> &b) {
    // Memoization
    // int sizeA = a.size();
    // int sizeB = b.size();
    // int diff = sizeA - sizeB;
    // vector<vector<int>> dp(sizeA, vector<int>(sizeB, -1));
    
    // return maxDotProductMemo(0, 0, diff, a, b, dp);
    
    // Tabulation
    return maxDotProductTab(a, b);
    }
};
