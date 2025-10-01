class Solution {
  public:
    vector<vector<int>> ans;
    vector<int> temp;
    vector<bool> used;
    
    void backtrack(vector<int>& arr) {
        if (temp.size() == arr.size()) {
            ans.push_back(temp);
            return;
        }
        for (int i = 0; i < arr.size(); i++) {
            if (used[i]) continue;
            if (i > 0 && arr[i] == arr[i-1] && !used[i-1]) continue;
            used[i] = true;
            temp.push_back(arr[i]);
            backtrack(arr);
            temp.pop_back();
            used[i] = false;
        }
    }
    
    vector<vector<int>> uniquePerms(vector<int>& arr) {
        sort(arr.begin(), arr.end());
        used.assign(arr.size(), false);
        backtrack(arr);
        return ans;
    }
};