class Solution {
  public:
    //Jay
     vector<int> topKFreq(vector<int> &arr, int k) {
        unordered_map<int, int> freq;
        for (int num : arr) freq[num]++;
        
        
        auto cmp = [](pair<int, int>& a, pair<int, int>& b) {
            if (a.first == b.first) return a.second > b.second;
            return a.first > b.first;
        };
        
        priority_queue<pair<int, int>, vector<pair<int, int>>, decltype(cmp)> pq(cmp);
        
        for (auto &it : freq) {
            pq.push({it.second, it.first});
            if (pq.size() > k) pq.pop();
        }
        
        vector<int> ans;
        while (!pq.empty()) {
            ans.push_back(pq.top().second);
            pq.pop();
        }
        
        reverse(ans.begin(), ans.end());
        return ans;
    }
};
