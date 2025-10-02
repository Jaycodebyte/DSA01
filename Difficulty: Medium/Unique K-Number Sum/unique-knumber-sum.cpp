class Solution {
  public:
     vector<vector<int>> ans;
    vector<int> temp;
    
    void backtrack(int start, int n, int k) {
        if (n == 0 && k == 0) {
            ans.push_back(temp);
            return;
        }
        if (n < 0 || k < 0) return;
        
        for (int i = start; i <= 9; i++) {
            temp.push_back(i);
            backtrack(i + 1, n - i, k - 1);
            temp.pop_back();
        }
    }
    
    vector<vector<int>> combinationSum(int n, int k) {
        backtrack(1, n, k);
        return ans;
    }
};