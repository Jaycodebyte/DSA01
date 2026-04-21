class Solution {
  public:
  //Jay
   int gcd(int a, int b) {
        if (b == 0) return a;
        return gcd(b, a % b);
    }

    int fun(int fromCap, int toCap, int d) {
        int from = fromCap;   // fill first jug
        int to = 0;
        int steps = 1;

        while (from != d && to != d) {
            int temp = min(from, toCap - to);

            to += temp;
            from -= temp;
            steps++;

            if (from == d || to == d) break;

            if (from == 0) {
                from = fromCap;
                steps++;
            }

            if (to == toCap) {
                to = 0;
                steps++;
            }
        }
        return steps;
    }

    int minSteps(int n, int m, int d) {
        if (d > max(n, m)) return -1;
        if (d % gcd(n, m) != 0) return -1;

        return min(fun(n, m, d), fun(m, n, d));
    }
};