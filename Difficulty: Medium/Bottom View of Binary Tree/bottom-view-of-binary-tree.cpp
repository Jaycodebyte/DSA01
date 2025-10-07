/*
class Node {
public:
    int data;
    Node* left;
    Node* right;

    Node(int x) {
        data = x;
        left = right = NULL;
    }
};
*/

class Solution {
  public:
      vector<int> bottomView(Node *root) {
        vector<int> ans;
        if (!root) return ans;
        
        map<int, int> hd_map;
        queue<pair<Node*, int>> q;
        q.push({root, 0});
        
        while (!q.empty()) {
            auto it = q.front();
            q.pop();
            Node* node = it.first;
            int hd = it.second;
            
            hd_map[hd] = node->data;
            
            if (node->left) q.push({node->left, hd - 1});
            if (node->right) q.push({node->right, hd + 1});
        }
        
        for (auto p : hd_map)
            ans.push_back(p.second);
        
        return ans;
    }
};