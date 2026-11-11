class Solution {
public:

    int recursion(int rowIndex, int colIndex){
        if(rowIndex < 0) return 0;
        if(colIndex < 0) return 0;
        if(colIndex == 0 && rowIndex == 0) return 1;
        // going left
        int left = recursion(rowIndex, colIndex - 1);
        // going top
        int top = recursion(rowIndex - 1, colIndex);
        return left + top;
    }

    int memoization(int rowIndex, int colIndex, vector<vector<int>>& dp){
        if(rowIndex < 0) return 0;
        if(colIndex < 0) return 0;
        if(colIndex == 0 && rowIndex == 0) return 1;
        if(dp[rowIndex][colIndex] != -1) return dp[rowIndex][colIndex];
        // going left
        int left = memoization(rowIndex, colIndex - 1, dp);
        // going top
        int top = memoization(rowIndex - 1, colIndex, dp);
        return dp[rowIndex][colIndex] = left + top;
    }

    int tabulation(int row, int col){
        vector<vector<int>> dp(row, vector<int>(col, -1));
        dp[0][0] = 1; //because there is only one way and that is by staying there.
        for(int rowIndex = 0; rowIndex < row; rowIndex++){
            for(int colIndex = 0; colIndex < col; colIndex++){
                if(rowIndex == 0 && colIndex == 0) continue;
                int left = 0;
                int top = 0;
                if(colIndex > 0) left = dp[rowIndex][colIndex - 1];
                if(rowIndex > 0) top = dp[rowIndex - 1][colIndex];
                dp[rowIndex][colIndex] = left + top;
            }
        }
        return dp[row-1][col-1];
    }

    int uniquePaths(int m, int n) {
        //Method 1: Recursion: TC: O(2^(m+n)) and SC: O(m+n)
        // return recursion(m-1, n-1);

        //Method 2: Memoization: TC: O(m x n) and SC: O(m+n) + O(m x n)
        // //2D dp
        // vector<vector<int>> dp(m, vector<int>(n, -1));
        // return memoization(m-1, n-1, dp);

        //Method 3: Tabulation: TC: O(m x n) and SC: O(mxn)
        return tabulation(m, n);
    }
};