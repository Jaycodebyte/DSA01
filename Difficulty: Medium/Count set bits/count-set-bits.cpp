class Solution {
  public:
  //Jay
    int countSetBits(int n) {
        int count = 0;
        for(int i = 0; (1 << i) <= n; i++) {
            int block = 1 << (i + 1);
            int fullCycles = (n + 1) / block;
            count += fullCycles * (1 << i);

            int remainder = (n + 1) % block;
            if (remainder > (1 << i))
                count += remainder - (1 << i);
        }
        return count;
    }
};
