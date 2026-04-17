class Solution {
  public:
  //Jay
    bool canFormPalindrome(string s) {
        vector<int> freq(26, 0);
        bool iseven = (s.length() % 2 == 0);

        for(int i = 0; i < s.length(); i++) {
            int idx = s[i] - 'a';
            if(freq[idx] == 1) {
                freq[idx] = 0;
            } else {
                freq[idx] = 1;
            }
        }

        int sum = 0;
        for(int i = 0; i < 26; i++) {
            sum += freq[i];
        }

        if((iseven && sum == 0) || (!iseven && sum == 1)) 
            return true;

        return false;
        
    }
};