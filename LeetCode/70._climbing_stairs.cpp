class Solution {
public:
    int climbStairs(int n) {
        double sqrt5 = sqrt(5);
        double fibo = pow((1 + sqrt5) / 2, n + 1) - pow((1 - sqrt5) / 2, n + 1);
        return (int)round(fibo / sqrt5);
    }
};
