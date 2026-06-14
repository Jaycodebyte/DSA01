class Solution {
  public:
  //Jay
    vector<int> exitPoint(vector<vector<int>>& mat) {
        int n = mat.size(), m = mat[0].size();

        int dirR[4] = {0, 1, 0, -1};
        int dirC[4] = {1, 0, -1, 0};

        int row = 0, col = 0;
        int dir = 0; // 0=Right, 1=Down, 2=Left, 3=Up

        while(row >= 0 && row < n && col >= 0 && col < m) {

            if(mat[row][col] == 1) {
                dir = (dir + 1) % 4; // turn clockwise
                mat[row][col] = 0;
            }

            row += dirR[dir];
            col += dirC[dir];
        }

        row -= dirR[dir];
        col -= dirC[dir];

        return {row, col};
    }
};