class Solution {
  public:
  //Jay
      vector<int> PGE(vector<int> &arr) {
        int n = arr.size();
        vector<int> pge(n);
        stack<int> st;

        for (int i = 0; i < n; i++) {
            while (!st.empty() && arr[i] > arr[st.top()])
                st.pop();
            pge[i] = st.empty() ? -1 : st.top();
            st.push(i);
        }
        return pge;
    }

    vector<int> NGE(vector<int> &arr) {
        int n = arr.size();
        vector<int> nge(n);
        stack<int> st;

        for (int i = n - 1; i >= 0; i--) {
            while (!st.empty() && arr[i] > arr[st.top()])
                st.pop();
            nge[i] = st.empty() ? n : st.top();
            st.push(i);
        }
        return nge;
    }

    int maxPeople(vector<int> &arr) {
        int n = arr.size();
        vector<int> pge = PGE(arr);
        vector<int> nge = NGE(arr);

        int maxi = 0;
        for (int i = 0; i < n; i++) {
            maxi = max(maxi, nge[i] - pge[i] - 1);
        }
        return maxi;
    }
};