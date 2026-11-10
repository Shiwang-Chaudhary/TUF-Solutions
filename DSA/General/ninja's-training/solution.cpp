class Solution {
public:

    int recursion(int index, int last, vector<vector<int>>& matrix){
        if(index < 0) return 0;
        int merit = 0;
        for(int i = 0; i < 3; i++){ //0,1,2
            if(i == last) continue;
            int val = matrix[index][i] + recursion(index-1, i, matrix);
            merit = max(merit, val);
        }
        return merit;
    }

    int memoization(int index, int last, vector<vector<int>>& dp, vector<vector<int>>& matrix){
        if(index < 0) return 0;
        if(dp[index][last] != -1) return dp[index][last];
        int merit = 0;
        for(int i = 0; i < 3; i++){
            if(i == last) continue;
            int val = matrix[index][i] + memoization(index - 1, i, dp, matrix);
            merit = max(merit, val);
            
        }
        return dp[index][last] = merit;
    }

    int ninjaTraining(vector<vector<int>>& matrix) {
        //Method 1: Recursion: TC: O(3^n) and SC: O(n)
        // int n = matrix.size();
        // return recursion(n-1, 3, matrix);

        //Method 2: Memoization: TC: O()
        int n = matrix.size();
        //2D dp
        vector<vector<int>>dp(n, vector<int>(4, -1)); //4 because there are 4 choices 0,1,2,3 where 3 represent None selected
        return memoization(n-1, 3, dp, matrix);
    }
};