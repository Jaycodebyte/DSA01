class Solution {
  public:
  //Jay
      bool isPossible(vector<int>& arr, int k, long long maxTime) {
        long long currentSum = 0;
        int painters = 1;
        
        for(int i = 0; i < arr.size(); i++) {
            
            if(arr[i] > maxTime) return false;
            
            if(currentSum + arr[i] <= maxTime) {
                currentSum += arr[i];
            } 
            else {
                painters++;
                currentSum = arr[i];
            }
        }
        
        return painters <= k;
    }
  
  
    int minTime(vector<int>& arr, int k) {
        
        long long low = 0, high = 0;
        
      
        for(int i = 0; i < arr.size(); i++) {
            low = max(low, (long long)arr[i]); 
            high += arr[i]; 
        }
        
        long long ans = high;
        
     
        while(low <= high) {
            long long mid = low + (high - low) / 2;
            
            if(isPossible(arr, k, mid)) {
                ans = mid;
                high = mid - 1; 
            } 
            else {
                low = mid + 1; 
            }
        }
        
        return ans;
    }
};