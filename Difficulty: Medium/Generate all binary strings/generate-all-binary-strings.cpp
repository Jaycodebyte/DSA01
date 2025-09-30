class Solution {
  public:
   //Jay
     vector<string> binstr(int n) {
        vector<string> result;
        int total = 1 << n;  // 2^n

        for (int i = 0; i < total; i++) {
            string s = bitset<20>(i).to_string();
            result.push_back(s.substr(20 - n));   // take last n bits
        }
        return result;
    }
};