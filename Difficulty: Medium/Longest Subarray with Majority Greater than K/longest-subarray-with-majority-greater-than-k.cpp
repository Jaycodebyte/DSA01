class Solution {
  public:
  //Jay
     int longestSubarray(vector<int> &arr, int k) {
        unordered_map<int, int> mp;
        int n = arr.size();
        int prefix = 0, maxLen = 0;
        
        for(int i = 0; i < n; i++) {
            if(arr[i] > k) prefix += 1;
            else prefix -= 1;
            
            if(prefix > 0) {
                maxLen = i + 1;
            } else {
                if(mp.find(prefix - 1) != mp.end()) {
                    maxLen = max(maxLen, i - mp[prefix - 1]);
                }
            }
            
            if(mp.find(prefix) == mp.end()) {
                mp[prefix] = i;
            }
        }
        
        return maxLen;
    }
};