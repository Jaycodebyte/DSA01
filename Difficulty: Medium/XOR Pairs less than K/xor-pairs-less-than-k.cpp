class Solution {
  public:
   //Jay
    struct Trie {
        Trie* child[2];
        int cnt;
        Trie() {
            child[0] = child[1] = nullptr;
            cnt = 0;
        }
    };

    Trie* root;

    void insert(int num) {
        Trie* node = root;
        for(int i = 15; i >= 0; i--) {
            int bit = (num >> i) & 1;
            if(!node->child[bit])
                node->child[bit] = new Trie();
            node = node->child[bit];
            node->cnt++;
        }
    }

    int countLess(int num, int k) {
        Trie* node = root;
        int ans = 0;

        for(int i = 15; i >= 0; i--) {
            if(!node) break;

            int b1 = (num >> i) & 1;
            int b2 = (k >> i) & 1;

            if(b2 == 1) {
                if(node->child[b1])
                    ans += node->child[b1]->cnt;
                node = node->child[1 - b1];
            } else {
                node = node->child[b1];
            }
        }

        return ans;
    }

    int cntPairs(vector<int>& arr, int k) {
        root = new Trie();
        int ans = 0;

        for(int num : arr) {
            ans += countLess(num, k);
            insert(num);
        }
        return ans;
    }
};