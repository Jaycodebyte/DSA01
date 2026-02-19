class Solution {
  public:
  //Jay
    vector<int> missinRange(vector<int>& arr, int low, int high) {
        unordered_set<int> st(arr.begin(), arr.end());
        vector<int> result;
        
        for(int num = low; num <= high; num++) {
            if(st.find(num) == st.end()) {
                result.push_back(num);
            }
        }
        
        return result;
    }
};