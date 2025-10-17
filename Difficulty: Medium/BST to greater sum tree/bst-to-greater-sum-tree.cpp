/*
class Node {
  public:
    int data;
    Node* left;
    Node* right;

    Node(int value) {
        data = value;
        left = nullptr;
        right = nullptr;
    }
};*/

class Solution {
  public:
     //Jay
     int sum = 0;
     void transformTree(Node *root) {
        if(!root) return;
        transformTree(root->right);
        int old = root->data;
        root->data = sum;
        sum += old;
        transformTree(root->left);
    }
};