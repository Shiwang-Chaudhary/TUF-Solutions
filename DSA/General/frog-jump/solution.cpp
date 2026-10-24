class Solution {
public:
    //NOTE: i represent the current index that we jumped to
    // long long solve1(int i, vector<int>& heights){
    //     if(i == 0) return 0;
    //     //if we jump from i-1 index to i index then
    //     long long left = solve1(i-1, heights) + abs(heights[i-1] - heights[i]);
    //     //if we jump from i-2 to i index then
    //     long long right = LLONG_MAX; // just for initialization, nothing else
    //     if(i > 1){
    //         //i must be > 1 because i-2 then be 0 or more than 0
    //         right = solve1(i-2, heights) + abs(heights[i-2] - heights[i]);
    //     }
    //     //take only the minimum out of left and right
    //     return min(left, right);
    // }

    //Memoization method: TC: O(n) and SC: O(n)+ O(n)[recursion stack and dp array]
    int solve2(int i, vector<int>& heights, vector<int>& dp){
        if(i == 0) return 0;
        if(dp[i] != -1) return dp[i];
        //if we jump from i-1 index to i index then        
        int left = solve2(i-1, heights, dp) + abs(heights[i-1] - heights[i]);
        //if we jump form i-2 to i index then
        int right = INT_MAX;
        if(i > 1) right = solve2(i-2, heights, dp) + abs(heights[i-2] - heights[i]);
        dp[i] = min(left, right);
        return dp[i];
    }

    int solve3(vector<int>& heights){
        int n = heights.size();
        vector<int> dp(n, -1);
        dp[0] = 0;
        int right = INT_MAX;
        for(int i = 1; i < n; i++){
            int left = dp[i-1] + abs(heights[i] - heights[i-1]);
            if(i > 1){
                right = dp[i-2] + abs(heights[i] - heights[i-2]);
            }
            dp[i] = min(left, right);
        }
        return dp[n-1];
    }

    int solve4(vector<int>& heights){
        int p1 = 0; //(represent i-1)
        int p2 = 0; // (represent i-2)
        int right = INT_MAX;
        int current = 0;
        for(int i = 1; i < heights.size(); i++){
            int left = p1 + abs(heights[i] - heights[i-1]);
            if(i > 1){
                right = p2 + abs(heights[i] - heights[i-2]);
            }
            current = min(left, right);
            p2 = p1;
            p1 = current;
        }
        return current;
    }
    
    int frogJump(vector<int>& heights) {
        //Method 1: Recursion method without DP, TC: O(2^n) and SC: O(n)
        int n = heights.size();
        // return solve1(n-1, heights);

        //Method 2: Memoization
        // vector<int> dp(n+1, -1);
        // return solve2(n-1, heights, dp);

        //Method 3: Tabulation
        return solve4(heights);
    }
};