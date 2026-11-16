class Solution{   
public:

    //it represent "Can we return target sum from the subset of arr from 0th to 'index' index?"
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
        //dp[index][target] represent "Can we form sum t using elements from index 0 to i?"
        if(dp[index][target] != -1) return dp[index][target];

        bool picked = memoization(index - 1, target - arr[index], arr, dp);        
        bool notpicked = memoization(index - 1, target, arr, dp);        
        return dp[index][target] = picked || notpicked;
    }

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

    bool optimization(vector<int>&arr, int target){
        int n = arr.size();
        vector<int> prev(target + 1, 0); // initially false
        prev[0] = 1;
        if(arr[0] <= target) prev[arr[0]] = 1;
        for(int i = 1; i < n; i++){
            vector<int> curr(target + 1, 0);
            curr[0] = 1;
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

    bool isSubsetSum(vector<int>&arr, int target){
        int n = arr.size();
        //Method 1: Recursion: TC: O(2^n) and SC: O(n)[recursion stack]
        // return recursion(n - 1, target, arr);

        //Method 2: Memoization:
        //Note: 1 means true, 0 means false, -1 means unvisited
        // vector<vector<int>>dp(n, vector<int>(target + 1, -1));
        // return memoization(n - 1, target, arr, dp);

        //Method 3: tabulation
        // return tabulation(target, arr);

        //Method 4: Space optimization: 
        return optimization(arr, target);
    }   
};