class Solution {
  public:
  //Jay
     int countIncreasing(vector<int>& arr) {
        int n = arr.size();
        int len = 1;
        int ans = 0;
        
        for(int i = 1; i < n; i++) {
            
            if(arr[i] > arr[i-1]) {
                len++;
            } else {
                if(len >= 2)
                    ans += (len * (len - 1)) / 2;
                len = 1;
            }
        }
        
        if(len >= 2)
            ans += (len * (len - 1)) / 2;
        
        return ans;
     }
};
