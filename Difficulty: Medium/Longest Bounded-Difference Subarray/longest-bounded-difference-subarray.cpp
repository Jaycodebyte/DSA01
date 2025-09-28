class Solution {
  public:
     vector<int> longestSubarray(vector<int>& arr, int x) {
        int n = arr.size();
        int maxLen = 1;
        int bestStart = 0;
        
        int left = 0;
        multiset<int> window;
        
        for (int right = 0; right < n; right++) {
            window.insert(arr[right]);
            
            while (*window.rbegin() - *window.begin() > x) {
                window.erase(window.find(arr[left]));
                left++;
            }
            
            int currentLen = right - left + 1;
            if (currentLen > maxLen) {
                maxLen = currentLen;
                bestStart = left;
            }
        }
        
        vector<int> result;
        for (int i = bestStart; i < bestStart + maxLen; i++) {
            result.push_back(arr[i]);
        }
        
        return result;
    }
};