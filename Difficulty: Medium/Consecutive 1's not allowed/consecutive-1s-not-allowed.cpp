class Solution {
  public:
  //Jay
  int countStrings(int n) {
        if(n == 1) return 2;
        int prev2 = 2; 
        int prev1 = 3; 
        for(int i = 3; i <= n; i++) {
            int curr = prev1 + prev2;
            prev2 = prev1;
            prev1 = curr;
        }
        
        return prev1;
    }
};