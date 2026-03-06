class Solution {
  public:
  //Jay
   string minWindow(string s, string p) {
        vector<int> need(256, 0);
        vector<int> window(256, 0);
        
        for(char c : p) {
            need[c]++;
        }
        
        int left = 0, count = 0;
        int start = 0, minLen = INT_MAX;
        
        for(int right = 0; right < s.size(); right++) {
            char c = s[right];
            window[c]++;
            
            if(need[c] != 0 && window[c] <= need[c]) {
                count++;
            }
            
            while(count == p.size()) {
                if(right - left + 1 < minLen) {
                    minLen = right - left + 1;
                    start = left;
                }
                
                char lc = s[left];
                window[lc]--;
                
                if(need[lc] != 0 && window[lc] < need[lc]) {
                    count--;
                }
                
                left++;
            }
        }
        
        if(minLen == INT_MAX) return "";
        
        return s.substr(start, minLen);
    }
};