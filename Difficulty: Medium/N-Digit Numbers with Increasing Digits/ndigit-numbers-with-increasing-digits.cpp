class Solution {
  public:
   void solve(int n,vector<int>&ans,int prev,int count,int num){
        if(count==n){
            ans.push_back(num);
            return;
        }
        for(int i=1;i<=9;i++){
            if(i>prev){
                solve(n,ans,i,count+1,num*10+i);
            }
        }
    }
    vector<int> increasingNumbers(int n) {
        // code here
        vector<int>ans;
        if(n>=10){
            return {};
        }
        if(n==1){
            for(int i=0;i<=9;i++){
                ans.push_back(i);
            }
            return ans;
        }
        solve(n,ans,0,0,0);
        return ans;
    }
};