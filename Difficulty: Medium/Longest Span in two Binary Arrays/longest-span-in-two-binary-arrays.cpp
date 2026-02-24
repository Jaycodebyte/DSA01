class Solution {
  public:
  //Jay
    int equalSumSpan(vector<int> &a1, vector<int> &a2) {
        unordered_map<int, int> mp;
        int n = a1.size();
        int sum = 0, maxLen = 0;
        
        mp[0] = -1;
        
        for(int i = 0; i < n; i++) {
            sum += (a1[i] - a2[i]);
            
            if(mp.find(sum) != mp.end()) {
                maxLen = max(maxLen, i - mp[sum]);
            } else {
                mp[sum] = i;
            }
        }
        
        return maxLen;
    }
};