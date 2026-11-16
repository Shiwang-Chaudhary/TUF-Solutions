class Solution{
	public:

    //it represent "Can we return target sum from the subset of arr from 0th to 'index' index?"
    int recursion(int index, int target, vector<int>&arr){
        if(target == 0) return true;
        if(index == 0) return arr[0] == target;
        
        int notpicked = recursion(index - 1, target, arr);        
        int picked = false;
        if(target - arr[index] >= 0){
            picked = recursion(index - 1, target - arr[index], arr);        
        }
        return picked + notpicked;
    }

    int memoization(int index, int target, vector<int>&arr, vector<vector<int>>& dp){
        if(target == 0) return true;
        if(index == 0) return arr[0] == target;

        //dp[index][target] represent "Can we form sum t using elements from index 0 to i?"
        if(dp[index][target] != -1) return dp[index][target];
        int notpicked = memoization(index - 1, target, arr, dp);        
        int picked = false;
        if(target - arr[index] >= 0){
            picked = memoization(index - 1, target - arr[index], arr, dp);        
        }
        return dp[index][target] = (picked + notpicked)% 1000000007;
    }

    int tabulation(int target, vector<int>&arr){
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
                int picked = false;
                if(j - arr[i] >= 0) picked = dp[i-1][j - arr[i]];
                int notpicked = dp[i-1][j];
                dp[i][j] = (picked + notpicked)% 1000000007;
            }
        }
        return dp[n-1][target];
    }

    int optimization(vector<int>&arr, int target){
        int n = arr.size();
        vector<int> prev(target + 1, 0); // initially false
        prev[0] = 1; //dp[i][0] must be true;
        if(arr[0] <= target) prev[arr[0]] = 1;
        for(int i = 1; i < n; i++){
            vector<int> curr(target + 1, 0); // initially false
            curr[0] = 1; //dp[i][0] must be true;
            for(int j = 1; j <= target; j++){
                int picked = false;
                if(j-arr[i] >= 0) picked = prev[j-arr[i]];
                int notpicked = prev[j];
                curr[j] = (picked + notpicked)% 1000000007;
            }
            prev = curr;
        }
        return prev[target];
    }

	int perfectSum(vector<int>&arr, int target){
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