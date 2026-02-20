class Solution {
  public:
  //Jay
     string findLargest(vector<int> &arr) {
        vector<string> nums;
        
        for(int num : arr) {
            nums.push_back(to_string(num));
        }
        
        sort(nums.begin(), nums.end(), [](string &a, string &b) {
            return a + b > b + a;
        });
        
        if(nums[0] == "0") return "0";
        
        string result = "";
        for(string &s : nums) {
            result += s;
        }
        
        return result;
    }
};