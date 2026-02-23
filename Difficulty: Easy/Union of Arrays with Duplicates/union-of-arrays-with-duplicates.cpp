class Solution {
  public:
  //Jay
   vector<int> findUnion(vector<int>& a, vector<int>& b) {
        unordered_set<int> st;
        
        for(int num : a) {
            st.insert(num);
        }
        
        for(int num : b) {
            st.insert(num);
        }
        vector<int> result(st.begin(), st.end());
        return result;
    
    }
};