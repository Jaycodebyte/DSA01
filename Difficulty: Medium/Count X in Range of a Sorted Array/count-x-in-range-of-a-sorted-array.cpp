class Solution {
  public:
  //Jay
   vector<int> countXInRange(vector<int>& arr, vector<vector<int>>& queries) {

        unordered_map<int, vector<int>> mp;
        for(int i = 0; i < arr.size(); i++) {
            mp[arr[i]].push_back(i);
        }
        
        vector<int> ans;
    
        for(auto &q : queries) {
            int l = q[0];
            int r = q[1];
            int x = q[2];
        
            if(mp.find(x) == mp.end()) {
                ans.push_back(0);
                continue;
            }
        
            vector<int> &indices = mp[x];
            int left = lower_bound(indices.begin(), indices.end(), l) - indices.begin();
            int right = upper_bound(indices.begin(), indices.end(), r) - indices.begin();
            ans.push_back(right - left);
        }
        
        return ans;
    }
};