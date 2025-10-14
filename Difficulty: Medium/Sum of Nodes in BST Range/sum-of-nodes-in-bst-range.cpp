/*
class Node {
  public:
    int data;
    Node* left;
    Node* right;

    // Constructor to initialize a new node
    Node(int val) {
        data = val;
        left = NULL;
        right = NULL;
    }
};
*/

class Solution {
  public:
    //Jay
    int nodeSum(Node* root, int l, int r) {
        if (!root) return 0;
        if (root->data < l) return nodeSum(root->right, l, r);
        if (root->data > r) return nodeSum(root->left, l, r);
        return root->data + nodeSum(root->left, l, r) + nodeSum(root->right, l, r);
        
    }
};
