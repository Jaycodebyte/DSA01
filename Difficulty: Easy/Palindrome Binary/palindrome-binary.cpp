class Solution {
  public:
  //Jay
     bool isBinaryPalindrome(int n) {
        // code here
        string s = bitset<32>(n).to_string();
        
        int i = 0;
        while (i < s.length() && s[i] == '0') i++;
        string trimmed = s.substr(i);
        string rev = trimmed;
        reverse(rev.begin(), rev.end());
        
        return trimmed == rev;
    }
};