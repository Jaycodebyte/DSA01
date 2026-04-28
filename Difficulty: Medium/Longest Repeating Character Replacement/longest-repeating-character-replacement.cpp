class Solution {
  public:
   // Jay
    int longestSubstr(string s, int k) {
        unordered_map<char, int> hm;

        int left = 0;
        int maxLength = 0;
        int maxCount = 0;

        for (int right = 0; right < s.length(); right++) {
            char c = s[right];
            hm[c]++;

            maxCount = max(maxCount, hm[c]);

            while ((right - left + 1) - maxCount > k) {
                char ch = s[left];
                hm[ch]--;
                left++;
            }

            maxLength = max(maxLength, right - left + 1);
        }

        return maxLength;
    }
};