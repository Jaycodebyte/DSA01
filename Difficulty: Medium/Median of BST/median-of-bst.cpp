/*
class Node {
  public:
    int data;
    Node* left;
    Node* right;
    Node(int val) {
        data = val;
        left = right = nullptr;
    }
};
*/

class Solution {
  public:
    // Jay
    void inorder(Node* root, vector<int>& v) {
        if (!root) return;
        inorder(root->left, v);
        v.push_back(root->data);
        inorder(root->right, v);
    }
    
    int findMedian(Node* root) {
        vector<int> v;
        inorder(root, v);
        int n = v.size();
        if (n % 2 == 0) return v[(n/2) - 1];
        else return v[n/2];
    }
};