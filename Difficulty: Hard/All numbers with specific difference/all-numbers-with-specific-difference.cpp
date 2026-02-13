class Solution {
  public:
  //jay
    int digitsum(int num){
        int sum = 0;
        
        while(num){
            sum+=num%10;
            num/=10;
        }
        
        return sum;
    }
    
    int getCount(int n, int d) {
        // code here
        int ans = 0;
        
        int start = 10;
        int end = n;
        
        while(start<=end){
            
            int mid = start+((end-start)/2);
            
            int sum = digitsum(mid);
            
            int diff = mid - sum;
            
            if(diff>=d){
                ans+=(end-mid+1);
                end = mid-1;
            }
            else{
                start=mid+1;
            }
            
        }
        
        
        return ans;
    }
};