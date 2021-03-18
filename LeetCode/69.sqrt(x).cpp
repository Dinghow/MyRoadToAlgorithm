class Solution {
public:
    int mySqrt(int x) {
        if(x==1) return 1;
        int lower = 0;
        int upper = x;
        while(lower+1 < upper){
            long long mid = (lower + upper)/2;
            if (mid*mid > x) upper = mid;
            else if (mid*mid < x) lower = mid;
            else return mid;
        }
        return lower;
    }
};