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
    
    int tabulation(vector<vector<int>>& matrix){
        //Note: dp[index][last] represent recursion(index, last)
        int n = matrix.size();
        vector<vector<int>> dp(n, vector<int>(4, -1));
        dp[0][0] = max(matrix[0][1], matrix[0][2]); //if last is 0 then choose max btw (0,1) and (0,2)
        dp[0][1] = max(matrix[0][0], matrix[0][2]); //if last is 1 then choose max btw (0,0) and (0,2)
        dp[0][2] = max(matrix[0][0], matrix[0][1]); //if last is 2 then choose max btw (0,0) and (0,1)
        //if last is 3 then choose among (0,0), (0,1) and (0,2)
        int max1 = max(matrix[0][0], matrix[0][1]);
        dp[0][3] = max(max1, matrix[0][2]);

        for(int day = 1; day < n; day++){
            //last can be 0,1,2,3
            for(int last = 0; last < 4; last++){
                int merit = 0;
                for(int task = 0; task < 3; task++){
                    if(task == last) continue;
                    int val = matrix[day][task] + dp[day - 1][task];
                    merit = max(val, merit);
                }
                dp[day][last] = merit;
            }
        }
        return dp[n-1][3];
    }

    int optimized(vector<vector<int>>& matrix){
        int n = matrix.size();
        vector<int> prev(4, -1);        
        //p represent the day-1 state 
        prev[0] = max(matrix[0][1], matrix[0][2]); //if last is 0 then choose max btw (0,1) and (0,2)
        prev[1] = max(matrix[0][0], matrix[0][2]); //if last is 1 then choose max btw (0,0) and (0,2)
        prev[2] = max(matrix[0][0], matrix[0][1]); //if last is 2 then choose max btw (0,0) and (0,1)
        //if last is 3 then choose among (0,0), (0,1) and (0,2)
        int max1 = max(matrix[0][0], matrix[0][1]);
        prev[3] = max(max1, matrix[0][2]);
        int ans = 0;
        for(int day = 1; day < n; day++){
            vector<int>curr(4, -1);
            for(int last = 0; last < 4; last++){
                int merit = 0;
                for(int task = 0; task < 3; task++){
                    if(task == last) continue;
                    int val = matrix[day][task] + prev[task]; //day-1
                    merit = max(merit, val); // means current day
                }
                curr[last] = merit;
            }
            prev = curr;
        }
        return prev[3];
    }

    int ninjaTraining(vector<vector<int>>& matrix) {
        //Method 1: Recursion: TC: O(3^n) and SC: O(4n) + O(n)
        // int n = matrix.size();
        // return recursion(n-1, 3, matrix);

        //Method 2: Memoization: TC: O(Nx4x3) because last's val can be 0,1,2,3 and task can be 0,1,2 and SC: O(4n)+O(n)
        // int n = matrix.size();
        // //2D dp
        // vector<vector<int>>dp(n, vector<int>(4, -1)); //4 because there are 4 choices 0,1,2,3 where 3 represent None selected
        // return memoization(n-1, 3, dp, matrix);

        //Method 3: Tabulation: TC: O(Nx4x3) and SC: O(4n)
        // return tabulation(matrix);

        //Method 4: Optimized tabulation: TC: O(Nx4x3) and SC: O(1) [O(4 + 4) techincally (curr and prev vectors)]
        return optimized(matrix);
    }
};