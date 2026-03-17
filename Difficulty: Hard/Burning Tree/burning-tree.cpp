/*
class Node {
  public:
    int data;
    Node *left;
    Node *right;

    Node(int val) {
        data = val;
        left = right = NULL;
    }
};
*/

class Solution {
  public:
  //Jay
    int minTime(Node* root, int target) {
        unordered_map<Node*, Node*> parent;
        queue<Node*> q;
        q.push(root);
        
        Node* targetNode = NULL;
        
        while(!q.empty()) {
            Node* curr = q.front();
            q.pop();
            
            if(curr->data == target)
                targetNode = curr;
            
            if(curr->left) {
                parent[curr->left] = curr;
                q.push(curr->left);
            }
            
            if(curr->right) {
                parent[curr->right] = curr;
                q.push(curr->right);
            }
        }

        unordered_map<Node*, bool> visited;
        q.push(targetNode);
        visited[targetNode] = true;
        
        int time = 0;
        
        while(!q.empty()) {
            int size = q.size();
            bool spread = false;
            
            for(int i = 0; i < size; i++) {
                Node* curr = q.front();
                q.pop();
                
                // left child
                if(curr->left && !visited[curr->left]) {
                    spread = true;
                    visited[curr->left] = true;
                    q.push(curr->left);
                }
                
                // right child
                if(curr->right && !visited[curr->right]) {
                    spread = true;
                    visited[curr->right] = true;
                    q.push(curr->right);
                }
                
                // parent
                if(parent[curr] && !visited[parent[curr]]) {
                    spread = true;
                    visited[parent[curr]] = true;
                    q.push(parent[curr]);
                }
            }
            
            if(spread) time++;
        }
        
        return time;
    }
};