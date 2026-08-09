class Solution {
  public:
     int dp[1005][1005];
    int getall(int x,int y,vector<vector<int>>& mat){
        if(x == mat.size())return 0;
        if(dp[x][y]!=-1)return dp[x][y];
        if(y< 0 || y >= mat.size())return -1e9;
        int ans = mat[x][y];
        for(int j = 0;j<mat.size();j++){
            if(j == y)continue;
            ans = max(ans,mat[x][y] + getall(x + 1,j,mat));
        }
        return dp[x][y] = ans;
    }
    int zigzagSequence(vector<vector<int>>& mat) {
        // code here
        memset(dp,-1,sizeof dp);
        int ans = 0;
        for(int j = 0;j<mat.size();j++){
            ans = max(ans,getall(0,j,mat));
        }
        return ans;
    }
};