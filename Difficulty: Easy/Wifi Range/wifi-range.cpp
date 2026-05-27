class Solution {
  public:
    bool wifiRange(string &s, int x) {
        int lastCovered = -1;
        int n=s.size();
        for(int i = 0; i < n; i++) {
            
            if(s[i] == '1') {
                
                int left = max(0, i - x);
                int right = min(n - 1, i + x);
                
                if(left > lastCovered + 1)
                    return false;
                
                lastCovered = max(lastCovered, right);
            }
        }
        
        return lastCovered == n - 1;
    }
};