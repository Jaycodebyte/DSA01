class Solution {
  public:
  //Jay
   int countSubarrays(vector<int> &arr) {
        
        int n = arr.size();
        long long ans = 0;
        stack<int> st;
        
        for(int i = n - 1; i >= 0; i--) {
            
            while(!st.empty() && arr[st.top()] >= arr[i]) {
                st.pop();
            }
            
            int nextSmaller = st.empty() ? n : st.top();
            
            ans += nextSmaller - i;
            
            st.push(i);
        }
        
        return ans;
    }
};