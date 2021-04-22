#include<vector>
using namespace std;

class Solution {
public:
    string longestPalindrome(string s) {
        int max_length = 1, sta = 0;
        int length = s.size();
        if (length < 2){
            return s;
        }

        vector<vector<int>> dp(length, vector<int>(length));
        for(int i = 0; i < length; i++) dp[i][i] = 1;

        for(int L = 2; L <= length; L++){
            for(int i = 0; i < length; i++){
                int j = i + L - 1;
                if (j >= length) break;
                if(s[i] != s[j]) dp[i][j] = false;
                else{
                    if (j - i < 3) dp[i][j] = 1;
                    else dp[i][j] = dp[i+1][j-1];
                }
                if(dp[i][j] && j - i + 1 > max_length){
                    max_length = j - i + 1;
                    sta = i;
                }
            }
        }
        return s.substr(sta, max_length);
    }
};