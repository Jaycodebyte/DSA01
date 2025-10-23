class Solution {
  public:
    //Jay
     vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
        priority_queue<pair<int, pair<int, int>>> pq;
        for (auto &p : points) {
            int dist = p[0]*p[0] + p[1]*p[1];
            pq.push({dist, {p[0], p[1]}});
            if (pq.size() > k) pq.pop();
        }
        vector<vector<int>> ans;
        while (!pq.empty()) {
            ans.push_back({pq.top().second.first, pq.top().second.second});
            pq.pop();
        }
        return ans;
    }
};