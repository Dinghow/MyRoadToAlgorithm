class Solution {
public:
    int minimumTotal(vector<vector<int>>& triangle) {
        int row = triangle.size();
        vector<vector<int>> dp(row, vector<int>(row, INT_MIN));

        dp[0][0] = triangle[0][0];
        
        for(int i = 1; i < row; i++) dp[i][0] = dp[i-1][0] + triangle[i][0];

        for(int i = 1; i < row; i++){
            for(int j = 1; j < i+1; j++){
                if(dp[i-1][j] != INT_MIN && dp[i-1][j-1] != INT_MIN) dp[i][j] = min(dp[i-1][j], dp[i-1][j-1]) + triangle[i][j];
                else if(dp[i-1][j] != INT_MIN) dp[i][j] = dp[i-1][j] + triangle[i][j];
                else dp[i][j] = dp[i-1][j-1] + triangle[i][j];
            }
        }
        int min_p = dp[row-1][0];
        for(int i = 1; i < row; i++){
            if(dp[row-1][i] < min_p) min_p = dp[row-1][i];
        }
        return min_p;
    }
};