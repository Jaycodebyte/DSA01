class Solution {
  public:
  //Jay
     int countSquare(vector<vector<int>>& mat, int x) {
        int n = mat.size();
        int m = mat[0].size();

        vector<vector<int>> prefix(n, vector<int>(m, 0));
        
        for(int i = 0; i < n; i++) {
            for(int j = 0; j < m; j++) {
                prefix[i][j] = mat[i][j];
                
                if(i > 0)
                    prefix[i][j] += prefix[i - 1][j];
                if(j > 0)
                    prefix[i][j] += prefix[i][j - 1];
                if(i > 0 && j > 0)
                    prefix[i][j] -= prefix[i - 1][j - 1];
            }
        }
        
        int count = 0;
 
        for(int i = 0; i < n; i++) {
            for(int j = 0; j < m; j++) {

                for(int k = 1; i + k - 1 < n && j + k - 1 < m; k++) {
                    
                    int r = i + k - 1;
                    int c = j + k - 1;
                    
                    int sum = prefix[r][c];
                    
                    if(i > 0)
                        sum -= prefix[i - 1][c];
                    if(j > 0)
                        sum -= prefix[r][j - 1];
                    if(i > 0 && j > 0)
                        sum += prefix[i - 1][j - 1];
                    
                    if(sum == x)
                        count++;
                }
            }
        }
        
        return count;
    }
};