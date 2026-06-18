class Solution {
  public:
   int findCoverage(vector<vector<int>>& mat) {
        // code here
        int n=mat.size();
        int m=mat[0].size();

        for(int i=0; i<n; i++){
            bool one=0;
            for(int j=0; j<m; j++){
                if(mat[i][j]==1){
                    one=1;
                }else{
                    if(one) mat[i][j]--;
                }
            }
            one=0;
            for(int j=m-1; j>=0; j--){
                if(mat[i][j]==1){
                    one=1;
                }else{
                    if(one) mat[i][j]--;
                }
            }
        }

        for(int j=0; j<m; j++){
            bool one=0;
            for(int i=0; i<n; i++){
                if(mat[i][j]==1){
                    one=1;
                }else{
                    if(one) mat[i][j]--;
                }
            }
            one=0;
            for(int i=n-1; i>=0; i--){
                if(mat[i][j]==1){
                    one=1;
                }else{
                    if(one) mat[i][j]--;
                }
            }
        }

        int ans=0;

        for(int i=0; i<n; i++){
            for(int j=0; j<m; j++){
                if(mat[i][j]<0){
                    ans+=abs(mat[i][j]);
                }
            }
        }

        return ans;
    }
};
