class Solution {
  public:
     int maxSumWithK(vector<int>& arr, int k) {
        // code here
        int n = arr.size();
        
        vector<int> beh(n);
        beh[0] = arr[0];
        
        for(int i=1; i<n; i++){
            beh[i] = max(arr[i], beh[i-1]+arr[i]);
        }
        
        int winsum = 0;
        
        for(int i=0; i<k; i++) winsum+=arr[i];
        
        int ans = winsum;
        
        for(int st = 1; st<=n-k; st++){
            winsum-=arr[st-1];
            winsum+=arr[st+k-1];
            
            ans = max(ans, winsum);
            
            ans = max(ans, winsum + beh[st-1]);
        }
        
        return ans;
    }
};