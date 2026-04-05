class Solution {
  public:
  //Jay
   int totalWays(vector<int>& arr, int target) {
        int totalSum = 0;
        for(int x : arr) totalSum += x;
        if(abs(target) > totalSum) return 0;
        if((totalSum + target) % 2 != 0) return 0;
        
        int req = (totalSum + target) / 2;
        
        vector<int> dp(req + 1, 0);
        dp[0] = 1;
        
        for(int num : arr) {
            for(int j = req; j >= num; j--) {
                dp[j] += dp[j - num];
            }
        }
        
        return dp[req];

    }
};