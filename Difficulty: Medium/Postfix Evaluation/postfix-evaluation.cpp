class Solution {
  public:
       //Jay
   int solve(int a,int b){
      if(a*b<0 && a%b!=0){
          return (a/b)-1;
      }
      return a/b;
  }
     int evaluatePostfix(vector<string>& arr) {
        stack<int>st;
        int n=arr.size();
        for(int i=0;i<n;i++){
            if(isdigit(arr[i][0]) || (arr[i].size() > 1 && arr[i][0] == '-')){
                st.push(stoi(arr[i]));
            }
            else{
                int a=st.top();
                st.pop();
                int b=st.top();
                st.pop();
                string c=arr[i];
                if(c=="+"){
                    st.push(a+b);
                }
                else if(c=="-"){
                    st.push(b-a);
                }
                else if(c=="*"){
                    st.push(b*a);
                }
                else if(c=="/"){
                    st.push(solve(b,a));
                }
                else if(c=="^"){
                    st.push((int)pow(b,a));
                }
            }
        }
        return st.top();
    }
};