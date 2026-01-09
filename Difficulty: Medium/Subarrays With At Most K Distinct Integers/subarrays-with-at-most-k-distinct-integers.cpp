class Solution {
  public:
  //Jay
     int countAtMostK(vector<int> &arr, int k) {
        int n = arr.size();
        int l = 0;
        long long ans = 0;
        unordered_map<int,int> freq;

        for(int r = 0; r < n; r++) {
            freq[arr[r]]++;

            while(freq.size() > k) {
                freq[arr[l]]--;
                if(freq[arr[l]] == 0)
                    freq.erase(arr[l]);
                l++;
            }

            ans += (r - l + 1);
        }

        return ans;
    }
};