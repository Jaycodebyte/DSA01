/*
class Node {
  public:
    int data;
    Node* next;

    Node(int x){
        data = x;
        next = NULL;
    }
};
*/
class Solution {
  public:
      //Jay
     Node *reverseKGroup(Node *head, int k) {
     
        Node*temp=head;
        Node*temp2=head;
        
        while(temp!=nullptr){
                stack<int>st;
            for(int i=1;i<=k;i++){
                if(temp==nullptr){
                    break;
                }
                st.push(temp->data);
                temp=temp->next;
            }
            
            while(!st.empty()){
                int val=st.top();
                st.pop();
                temp2->data=val;
                temp2=temp2->next;
            }
            
        }
        return head;
    }
};