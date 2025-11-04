class Solution {
  public:
    //Jay
     int minCost(vector<int>& height) {
        int n = height.size();
        if (n == 1) return 0;
        
        int prev2 = 0, prev1 = abs(height[1] - height[0]);
        
        for (int i = 2; i < n; i++) {
            int oneStep = prev1 + abs(height[i] - height[i - 1]);
            int twoStep = prev2 + abs(height[i] - height[i - 2]);
            int curr = min(oneStep, twoStep);
            prev2 = prev1;
            prev1 = curr;
        }
        
        return prev1;
    }
};