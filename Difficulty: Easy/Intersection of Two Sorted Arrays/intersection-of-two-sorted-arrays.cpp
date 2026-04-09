class Solution {
  public:
  //Jay
    vector<int> intersection(vector<int>& a, vector<int>& b) {
        int i = 0, j = 0;
        int n = a.size(), m = b.size();
        
        vector<int> ans;
        while(i < n && j < m) {
            
            if(a[i] == b[j]) {
                if(ans.empty() || ans.back() != a[i])
                    ans.push_back(a[i]);
                
                i++;
                j++;
            }
            else if(a[i] < b[j]) {
                i++;
            }
            else {
                j++;
            }
        }
        
        return ans;
    }
};