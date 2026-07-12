class Solution {
  public:
  //Jay
     int maxAmount(vector<int>& arr, int k) {
        // code here
        int mod = 1000000007;
        priority_queue<int>max;
        int n=arr.size();
        int ans=0;
        for(int i=0;i<n;i++){
            max.push(arr[i]);
        }
        for(int i=1;i<=k;i++){
            int num=max.top();
            if(num<0){
                break;
            }
            max.pop();
            ans=(ans+num)%mod;
            num--;
            max.push(num);
        }
        return ans;
    }
};