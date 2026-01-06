class Solution {
  public:
  //Jay
   int maxSubarrayXOR(vector<int>& arr, int k) {
 
        int n = arr.size(), ans = 0;
        for(int i = 0, x = 0; i < n; i++) {
            x ^= arr[i];
            if(i - k >= 0) x ^= arr[i - k];
            if(i >= k - 1) ans = max(ans, x);
        }
        return ans;
    }
};