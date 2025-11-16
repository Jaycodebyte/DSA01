class Solution {
  public:
   //Jay
    int LCIS(vector<int> &a, vector<int> &b) {
        int n = a.size();
        int m = b.size();
        
        vector<int> dp(m, 0);
        
        for (int i = 0; i < n; i++) {
            int current_max = 0;
            
            for (int j = 0; j < m; j++) {
                
                if (a[i] > b[j]) {
                    // b[j] can be a predecessor
                    current_max = max(current_max, dp[j]);
                }
                else if (a[i] == b[j]) {
                    dp[j] = current_max + 1;
                }
            }
        }
    
        return *max_element(dp.begin(), dp.end());
    }
};