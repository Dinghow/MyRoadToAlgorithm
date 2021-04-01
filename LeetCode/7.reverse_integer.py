class Solution {
public:
    int reverse(int x) {
        long rever_x = 0;
        long tmp = 0;
        while (x != 0){
            tmp = x % 10;
            rever_x *= 10;
            rever_x += tmp;
            x /= 10;
        }
        if (rever_x >= INT_MAX || rever_x < INT_MIN)
            rever_x = 0;
        return rever_x;
    }
};