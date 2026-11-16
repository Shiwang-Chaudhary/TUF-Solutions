class Solution {
public:
    //Recursion: TC: O(2^n) and SC: O(n) [recursion stack]
    //it represent "Can we return target sum from the subset of arr from 0th to 'index' index?"
    bool recursion(int index, int target, vector<int>&arr){
        if(target == 0) return true;
        if(index == 0) return arr[0] == target;
        
        bool notpicked = recursion(index - 1, target, arr);        
        bool picked = false;
        if(target - arr[index] >= 0){
            picked = recursion(index - 1, target - arr[index], arr);        
        }
        return picked || notpicked;
    }
    //Memoization: TC: O(n x target) and SC: O(n)[recursion stack] + O(n x target)[dp array]
    bool memoization(int index, int target, vector<int>&arr, vector<vector<int>>& dp){
        if(target == 0) return true;
        if(index == 0) return arr[0] == target;

        //dp[index][target] represent "Can we form sum t using elements from index 0 to i?"
        if(dp[index][target] != -1) return dp[index][target];
        bool notpicked = memoization(index - 1, target, arr, dp);        
        bool picked = false;
        if(target - arr[index] >= 0){
            picked = memoization(index - 1, target - arr[index], arr, dp);        
        }
        return dp[index][target] = picked || notpicked;
    }
    //Tabulation: TC: O(n x target) and SC: O(n x target) [dp array]
    bool tabulation(int target, vector<int>&arr){
        int n = arr.size();
        //we only need true and false here, not true, false, unvisited
        vector<vector<int>>dp(n, vector<int>(target + 1, 0)); // initially false;
        //base cases:
        for(int i = 0; i < n; i++){
            dp[i][0] = 1; //because in recursion, if(target == 0) then return true;[index can be anything within range]
        }
        if(arr[0] <= target) dp[0][arr[0]] = 1;
        //two states(index, target) so two loops
        for(int i = 1; i < n; i++){ //we already took care of index = 0 cases in base case
            for(int j = 1; j <= target; j++){ // we already considered what happens if target = 0 in base case
                bool picked = false;
                if(j - arr[i] >= 0) picked = dp[i-1][j - arr[i]];
                bool notpicked = dp[i-1][j];
                dp[i][j] = picked || notpicked;
            }
        }
        return dp[n-1][target];
    }
    //Optimization: TC: O(n x target) and SC: O(2n) [prev and curr arrays]
    bool optimization(vector<int>&arr, int target){
        int n = arr.size();
        vector<int> prev(target + 1, 0); // initially false
        prev[0] = 1; //dp[i][0] must be true;
        if(arr[0] <= target) prev[arr[0]] = 1;
        for(int i = 1; i < n; i++){
            vector<int> curr(target + 1, 0); // initially false
            curr[0] = 1; //dp[i][0] must be true;
            for(int j = 1; j <= target; j++){
                bool picked = false;
                if(j-arr[i] >= 0) picked = prev[j-arr[i]];
                bool notpicked = prev[j];
                curr[j] = picked || notpicked;
            }
            prev = curr;
        }
        return prev[target];
    }

    bool equalPartition(int n, vector<int> nums) {
        int totalsum = 0;
        for(int i = 0; i < n; i++){
            totalsum += nums[i];
        }
        //basically if we find even 1 single subset with sum = totalsum/2 then that means remaining element contains in the second subset with sum = totalsum/2
        if(totalsum % 2 == 0) return optimization(nums, totalsum/2);
        return false;
    }
};