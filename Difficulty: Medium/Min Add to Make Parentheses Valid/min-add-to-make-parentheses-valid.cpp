class Solution {
  public:
    int minParentheses(string& s) {
        int open = 0, insertions = 0;
        
        for (char c : s) {
            if (c == '(') {
                open++;
            } else {
                if (open > 0) {
                    open--;  
                } else {
                    insertions++;  
                }
            }
        }
        
        return insertions + open; 
    }
};