class Solution {
  public:
  //Jay
   int countPartitions(vector<int>& arr, int diff) {
        int n = arr.size();
        int totalSum = 0;
        
        for(int x : arr) totalSum += x;

        if((totalSum + diff) % 2 != 0) return 0;
        int target = (totalSum + diff) / 2;
        vector<int> dp(target + 1, 0);
        dp[0] = 1;
        
        for(int i = 0; i < n; i++) {
            for(int j = target; j >= arr[i]; j--) {
                dp[j] += dp[j - arr[i]];
            }
        }
        
        return dp[target];
        
    }
};