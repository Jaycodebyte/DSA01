class Solution {
  public:
  //jay
      bool checkRedundancy(string &s) {
        
        stack<char> st;
        
        for(char& ch : s){
            
            if(ch == '(' || ch == '+' || ch == '-'|| ch == '*'|| ch == '/' ){
                st.push(ch);
            }else if(ch == ')'){
                if(st.top() == '(') return true;
                
                while(!st.empty() && st.top()!='('){
                    st.pop();
                }
                if(!st.empty() && st.top() == '('){
                    st.pop();
                }
            }
        }
        
        return false;
    }
};
