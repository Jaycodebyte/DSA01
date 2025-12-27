class Solution {
  public:
  //Jay
    int kthSmallest(vector<vector<int>> &mat, int k) {
        int n = mat.size();
        int low = mat[0][0];
        int high = mat[n-1][n-1];
        
        while (low < high) {
            int mid = low + (high - low) / 2;
            
            int cnt = 0;
            int row = n - 1, col = 0;
            
            while (row >= 0 && col < n) {
                if (mat[row][col] <= mid) {
                    cnt += row + 1;
                    col++;
                } else {
                    row--;
                }
            }
            
            if (cnt < k)
                low = mid + 1;
            else
                high = mid;
        }
        return low;
    }
};
