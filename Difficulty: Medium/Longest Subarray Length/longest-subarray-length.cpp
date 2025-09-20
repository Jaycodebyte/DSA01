class Solution {
  public:
         //Jay
      int longestSubarray(vector<int>& arr) {
        int n = arr.size();
        vector<int> nge_left(n, -1), nge_right(n, n);
        stack<int> st;

        for (int i = n - 1; i >= 0; --i) {
            while (!st.empty() && arr[st.top()] < arr[i]) {
                nge_left[st.top()] = i;
                st.pop();
            }
            st.push(i);
        }

        while (!st.empty()) st.pop();

        for (int i = 0; i < n; ++i) {
            while (!st.empty() && arr[st.top()] < arr[i]) {
                nge_right[st.top()] = i;
                st.pop();
            }
            st.push(i);
        }

        int maxi = 0;
        for (int i = 0; i < n; ++i) {
            int l = nge_right[i] - nge_left[i] - 1;
            int v = arr[i];
            if (v <= l) {
                maxi = max(maxi, l);
            }
        }
        return maxi;
    }
};