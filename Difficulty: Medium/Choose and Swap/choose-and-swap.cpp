class Solution {
  public:
  //Jay
    string chooseSwap(string s) {
        int n = (int)s.length();
        int seen = 0;
        vector<int> first_seen(26);
        for (int x = 0; x < n; x++) {
            int word_pos = s[x] - 97;
            int bit_mask = 1 << word_pos;
            if ((bit_mask & seen) > 0)
                continue;
            seen |= bit_mask;
            first_seen[word_pos] = x;
        }

        int best_swap_words = 0;
        int first_word_pos = -1;
        for (int x = 0; x < 26; x++) {
            int bit_mask = 1 << x;
            if ((bit_mask & seen) == 0)
                continue;
            int first_idx_seen = first_seen[x];
            for (int y = x + 1; y < 26; y++) {
                int y_bit_mask = 1 << y;
                if ((y_bit_mask & seen) == 0)
                    continue;
                int y_first_idx_seen = first_seen[y];
                if (first_idx_seen < y_first_idx_seen)
                    continue;
                if (first_word_pos == -1 || first_word_pos > y_first_idx_seen) {
                    first_word_pos = y_first_idx_seen;
                    best_swap_words = (y << 5) | x;
                }
            }
            if (first_word_pos != -1)
                break;
        }

        if (first_word_pos == -1)
            return s;

        int first_word = best_swap_words >> 5;
        int second_word = best_swap_words & ((1 << 5) - 1);
        char c1 = static_cast<char>(first_word + 97);
        char c2 = static_cast<char>(second_word + 97);

        for (int x = 0; x < n; x++) {
            if (s[x] == c1) s[x] = c2;
            else if (s[x] == c2) s[x] = c1;
        }
        return s;
    }
};
