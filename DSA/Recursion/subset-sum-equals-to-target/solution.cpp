class Solution{   
public:

    bool recursion(int index, int target, vector<int>&arr){
        if(target == 0) return true;
        if(index < 0) return false;
        
        // bool picked = recursion(index - 1, target - arr[index], arr);
        // if(picked == true) return true;
        // bool notpicked = recursion(index - 1, target, arr);
        // if(notpicked == true) return true;
        // return false;

        // or
        bool picked = recursion(index - 1, target - arr[index], arr);        
        bool notpicked = recursion(index - 1, target, arr);        
        return picked || notpicked;
    }

    bool memoization(int index, int target, vector<int>&arr, vector<vector<int>>& dp){
        if(target == 0) return true;
        if(target < 0) return false;
        if(index < 0) return false;
        if(dp[index][target] != -1) return dp[index][target];

        bool picked = memoization(index - 1, target - arr[index], arr, dp);        
        bool notpicked = memoization(index - 1, target, arr, dp);        
        return dp[index][target] = picked || notpicked;

    }

    bool isSubsetSum(vector<int>&arr, int target){
        int n = arr.size();
        //Method 1: Recursion: TC: O(2^n) and SC: O(n)[recursion stack]
        // return recursion(n - 1, target, arr);

        //Method 2: Memoization:
        vector<vector<int>>dp(n, vector<int>(target + 1, -1));
        return memoization(n - 1, target, arr, dp);
    }   
};