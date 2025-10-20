class Solution {
  public:
    //Jay
     vector<int> countBSTs(vector<int>& arr) {
        int n = arr.size();
        if (n == 0) return {};
        
        // Catalan numbers 
        vector<int> catalan(n + 1, 0);
        catalan[0] = catalan[1] = 1;
        for (int i = 2; i <= n; i++) {
            for (int j = 0; j < i; j++) {
                catalan[i] += catalan[j] * catalan[i - j - 1];
            }
        }
        
        
        vector<int> sortedArr = arr;
        sort(sortedArr.begin(), sortedArr.end());
        
        vector<int> ans;
        for (int val : arr) {
            int idx = lower_bound(sortedArr.begin(), sortedArr.end(), val) - sortedArr.begin();
            int left = idx;
            int right = n - idx - 1;
            ans.push_back(catalan[left] * catalan[right]);
        }
        
        return ans;
    }
};