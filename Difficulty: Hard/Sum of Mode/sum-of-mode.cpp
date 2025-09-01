class Solution {
  public:
             //Jay
   struct Compare {
    bool operator()(const pair<int,int>& a, const pair<int,int>& b) const {
        if (a.first != b.first) return a.first > b.first; 
        return a.second < b.second; 
    }
};

int sumOfModes(vector<int>& arr, int k) {
    int n = arr.size();
    if (k > n) return 0;

    unordered_map<int,int> freq;
    multiset<pair<int,int>, Compare> ms;

    for (int i = 0; i < k; i++) {
        int x = arr[i];
        if (freq.count(x)) {
            ms.erase(ms.find({freq[x], x}));
        }
        freq[x]++;
        ms.insert({freq[x], x});
    }

    int sum = ms.begin()->second;

 
    for (int i = k; i < n; i++) {
        int add = arr[i];
        int rem = arr[i-k];

        
        ms.erase(ms.find({freq[rem], rem}));
        freq[rem]--;
        if (freq[rem] > 0) {
            ms.insert({freq[rem], rem});
        } else {
            freq.erase(rem);
        }

        if (freq.count(add)) {
            ms.erase(ms.find({freq[add], add}));
        }
        freq[add]++;
        ms.insert({freq[add], add});

  
        sum += ms.begin()->second;
    }

    return sum;
        
    }
};