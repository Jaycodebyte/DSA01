class Solution {
  public:
   //Jay
    vector<vector<int>> kSmallestPair(vector<int> &arr1, vector<int> &arr2, int k) {
        vector<vector<int>> result;
        if (arr1.empty() || arr2.empty() || k <= 0) return result;
        
        priority_queue<
            pair<int, pair<int, int>>,
            vector<pair<int, pair<int, int>>>,
            greater<pair<int, pair<int, int>>>>
            pq;
        
        for (int i = 0; i < arr1.size() && i < k; i++) {
            pq.push({arr1[i] + arr2[0], {i, 0}});
        }
        
        while (k-- && !pq.empty()) {
            auto top = pq.top();
            pq.pop();
            int i = top.second.first;
            int j = top.second.second;
            result.push_back({arr1[i], arr2[j]});
            
            if (j + 1 < arr2.size()) {
                pq.push({arr1[i] + arr2[j + 1], {i, j + 1}});
            }
        }
        
        return result;
    }
};
