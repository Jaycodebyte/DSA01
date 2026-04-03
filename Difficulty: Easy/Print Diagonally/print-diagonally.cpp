class Solution {
  public:
  //Jay
     vector<int> diagView(vector<vector<int>> mat) {
        int n = mat.size();
        vector<int> ans;
        
        for(int col = 0; col < n; col++) {
            int i = 0, j = col;
            
            while(i < n && j >= 0) {
                ans.push_back(mat[i][j]);
                i++;
                j--;
            }
        }
        for(int row = 1; row < n; row++) {
            int i = row, j = n - 1;
            
            while(i < n && j >= 0) {
                ans.push_back(mat[i][j]);
                i++;
                j--;
            }
        }
        return ans;
    }
};