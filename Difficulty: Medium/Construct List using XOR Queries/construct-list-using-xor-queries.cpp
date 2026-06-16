class Solution {
  public:
    vector<int> constructList(vector<vector<int>> &queries) {
        // code here
        vector<int> ans;
        ans.push_back(0);
        int xr=0;
        for(int i=0; i<queries.size(); i++){
            int x= queries[i][0];
            int ele= queries[i][1];
            if(x==0){
                ans.push_back(ele ^ xr);
            }
            else{
                xr= xr ^ ele;
            }
            
        }
        for(auto &ele: ans){
            ele= ele^ xr;
        } 
        sort(ans. begin(), ans.end());
        return ans;
        
    }
};
