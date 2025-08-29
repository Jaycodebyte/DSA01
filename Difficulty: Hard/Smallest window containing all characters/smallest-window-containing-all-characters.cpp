class Solution {
  public:
        //Jay
    string smallestWindow(string &s, string &p) {
    vector<int> freqP(26, 0);
    for (char ch : p) {
        freqP[ch - 'a']++;
    }
    vector<int> freqS(26, 0);  
    int required = p.size(); 
    int formed = 0;           
    int left = 0, right = 0;
    int minLen = INT_MAX;
    int startIdx = -1;

    
    while (right < s.size()) {
        char ch = s[right];
        freqS[ch - 'a']++;

        if (freqS[ch - 'a'] <= freqP[ch - 'a']) {
            formed++;
        }
        while (formed == required) {
            int windowLen = right - left + 1;

            if (windowLen < minLen) {
                minLen = windowLen;
                startIdx = left;
            }

            char leftChar = s[left];
            freqS[leftChar - 'a']--;

            if (freqS[leftChar - 'a'] < freqP[leftChar - 'a']) {
                formed--;
            }

            left++;
        }

        right++;
    }
    if (startIdx == -1) return "";
    return s.substr(startIdx, minLen);
    }
};