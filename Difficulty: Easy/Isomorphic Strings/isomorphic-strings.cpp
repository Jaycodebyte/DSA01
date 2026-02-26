class Solution {
  public:
  //Jay
     bool areIsomorphic(string &s1, string &s2) {
        
        if(s1.length() != s2.length()) return false;
        
        int m1[26], m2[26];

        for(int i = 0; i < 26; i++) {
            m1[i] = -1;
            m2[i] = -1;
        }
        
        for(int i = 0; i < s1.length(); i++) {
            
            int c1 = s1[i] - 'a';
            int c2 = s2[i] - 'a';
 
            if(m1[c1] == -1 && m2[c2] == -1) {
                m1[c1] = c2;
                m2[c2] = c1;
            }
 
            else if(m1[c1] != c2) {
                return false;
            }
        }
        
        return true;
    }
};