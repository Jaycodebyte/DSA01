class Solution {
  public:
     int minToggle(vector<int>& arr) {
        // code here
        int r0=0,l1=0;
        for(auto i:arr)if(i==0)r0++;
        int ans=r0;
        for(auto i:arr){
            if(i==0)r0--;
            else l1++;
            ans=min(ans,r0+l1);
        }
        return ans;
    }
};