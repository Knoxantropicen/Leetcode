// Time: O(log(n)), Space: O(1)
class Solution {
public:
    double myPow(double x, int n) {
        double result = 1;
        unsigned int pos_n = abs(n);
        while (pos_n > 0) {
            if (pos_n & 1) result *= x;
            x *= x;
            pos_n >>= 1;
        }
        return (n < 0) ? 1 / result : result;
    }
};