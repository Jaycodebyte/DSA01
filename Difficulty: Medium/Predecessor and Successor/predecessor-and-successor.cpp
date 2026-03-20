/* BST Node
class Node {
   public:
    int data;
    Node *left;
    Node *right;

    Node(int x){
        data = x;
        left = NULL;
        right = NULL;
    }
};
*/

class Solution {
  public:
  //Jay
   vector<Node*> findPreSuc(Node* root, int key) {
        
        Node* pred = NULL;
        Node* succ = NULL;
        Node* curr = root;
  
        while(curr) {
            if(curr->data < key) {
                pred = curr;
                curr = curr->right;
            }
            else if(curr->data > key) {
                succ = curr;
                curr = curr->left;
            }
            else {
                Node* temp = curr->left;
                while(temp) {
                    pred = temp;
                    temp = temp->right;
                }

                temp = curr->right;
                while(temp) {
                    succ = temp;
                    temp = temp->left;
                }
                
                break;
            }
        }
        
        return {pred, succ};
    }
};