class Solution {
  public:
  //jay
    vector<int> countDistinct(vector<int> &arr, int k) {
        vector<int> ans;
        unordered_map<int,int> freq;

        int n = arr.size();
        
        for(int i = 0; i < k; i++) {
            freq[arr[i]]++;
        }
        ans.push_back(freq.size());

        for(int i = k; i < n; i++) {

            int out = arr[i - k];
            freq[out]--;
            if(freq[out] == 0) {
                freq.erase(out);
            }

            freq[arr[i]]++;

            ans.push_back(freq.size());
        }

        return ans;
    }
};