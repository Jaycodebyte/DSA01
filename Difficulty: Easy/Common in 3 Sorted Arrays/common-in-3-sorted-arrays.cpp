class Solution {
  public:
  //Jay
   vector<int> commonElements(vector<int> &a, vector<int> &b, vector<int> &c) {
       
        int n=a.size();
        int m=b.size();
        int l=c.size();
        vector<int>ans;
        int i=0,j=0,k=0;
        while(i<n && j<m && k<l){
            if(a[i]==b[j] && b[j]==c[k]){
                if(ans.empty() || (!ans.empty() && ans.back()!=a[i]))
                ans.push_back(a[i]);
                i++;
                j++;
                k++;
            }
            else if(a[i]<=b[j] && a[i]<=c[k]){
                i++;
            }
            else if(a[i]>=b[j] && b[j]<=c[k]){
                j++;
            }
            else{
                k++;
            }
        }
        return ans;
    }
};