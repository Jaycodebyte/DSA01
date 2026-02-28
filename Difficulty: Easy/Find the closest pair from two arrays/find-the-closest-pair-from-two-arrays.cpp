class Solution {
  public:
  //Jay
    vector<int> findClosestPair(vector<int> &arr1, vector<int> &arr2, int x) {
        
        int n = arr1.size();
        int m = arr2.size();
        
        int i = 0;
        int j = m - 1;
        
        long long minDiff = LLONG_MAX;
        int a = 0, b = 0;
        
        while(i < n && j >= 0) {
            
            long long sum = (long long)arr1[i] + arr2[j];
            long long diff = abs(sum - x);
            
            if(diff < minDiff) {
                minDiff = diff;
                a = arr1[i];
                b = arr2[j];
            }
            
            if(sum > x) {
                j--;
            } else {
                i++;
            }
        }
        
        return {a, b};
    }
};