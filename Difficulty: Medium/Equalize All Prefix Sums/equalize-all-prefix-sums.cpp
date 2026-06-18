class Solution {
  public:
    vector<int> optimalArray(vector<int> &a) {
// code here
int n = a.size();
vector<int> ans;
 
for (int i = 0; i < n; i++) 
ans.push_back(a[i] - a[i >> 1]);
 
 
for (int i = 1; i < n; i++)
ans[i] += ans[i - 1];
 
 
return ans;
    }
};