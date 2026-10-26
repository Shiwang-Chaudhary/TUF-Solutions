class Solution {
public:
    int recursion(int index, vector<int>& heights, int k){
        if(index == 0) return 0;
        int minEnergy = INT_MAX;
        for(int i = 1; i <= k; i++){
            if(index - i >= 0){
                int energy = recursion(index - i, heights, k) + abs(heights[index] - heights[index - i]);
                minEnergy = min(minEnergy, energy);
            }
        }
        return minEnergy;
    }

    int memoization(int index, vector<int>&dp, vector<int>& heights, int k){
        if(index == 0) return 0;
        if(dp[index] != -1) return dp[index];
        int minEnergy = INT_MAX;
        for(int i = 1; i <= k; i++){
            if(index - i >= 0){
                int energy = memoization(index - i, dp, heights, k) + abs(heights[index] - heights[index - i]);
                minEnergy = min(minEnergy, energy);
                dp[index] = minEnergy;
            }
        }
        return dp[index];
    }
    int frogJump(vector<int>& heights, int k) {
        int n = heights.size();
        //Method 1: Recursion: TC: O(k^n) and SC: O(n) [recursion stack]
        // return recursion(n-1, heights, k);
        vector<int> dp(n, -1);
        return memoization(n-1, dp, heights, k);
    }
};
