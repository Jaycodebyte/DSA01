class Solution {
  public:
    int n;
    int dp[102][920];
    int f(int i,int prev,string &s){
        if(i==n)return 1;
        if(dp[i][prev]!=-1)return dp[i][prev];
        int cnt=0,curr_sum=0;
        for(int k=i;k<n;k++){
            curr_sum+=(s[k]-'0');
            if(prev<=curr_sum){
                cnt+=f(k+1,curr_sum,s);
            } 
        }
        return dp[i][prev]=cnt;
    }
    int validGroups(string &s) {
        // code here
        memset(dp,-1,sizeof(dp));
        n=s.size();
        int cnt=f(0,0,s);
        return cnt;
    }
};