class Solution {
  public:
  //Jay
     int countWays(int n, int k) {
        if(n == 1) return k;
  
        int prev2 = k;              
        int prev1 = k * k;          
        for(int i = 3; i <= n; i++) {
            int curr = (prev1 + prev2) * (k - 1);
            prev2 = prev1;
            prev1 = curr;
        }
        return prev1;
    }
};