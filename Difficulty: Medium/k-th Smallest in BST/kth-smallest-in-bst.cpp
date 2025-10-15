/*
class Node {
  public:
    int data;
    Node* left;
    Node* right;

    Node(int val) {
        data = val;
        left = right = NULL;
    }
};
*/

class Solution {
  public:
   // Jay
    int kthSmallest(Node *root, int k) {
        int count = 0, ans = -1;
        stack<Node*> st;
        Node* curr = root;
        while (curr || !st.empty()) {
            
            while (curr) {
                st.push(curr);
                curr = curr->left;
            }
            curr = st.top();
            st.pop();
            count++;
            if (count == k) {
                ans = curr->data;
                break;
            }
            curr = curr->right;
        }
        return ans;
    }
};