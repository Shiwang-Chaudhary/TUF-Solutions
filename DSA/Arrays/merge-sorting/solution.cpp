class Solution {
public:

    void merge(vector<int>& nums, int low, int mid, int high){
        vector<int> leftHalf;
        vector<int> rightHalf;
        vector<int> ans;
        //put left half and right half element in leftHalf and rightHalf arrays
        for(int i = low; i <= mid; i++){
            leftHalf.push_back(nums[i]);
        }
        for(int i = mid + 1; i <= high; i++){
            rightHalf.push_back(nums[i]);
        }
        int leftIndex = 0; //starting index for lefthalf array
        int rightIndex = 0; // starting index for righthalf array

        while(leftIndex < leftHalf.size() && rightIndex < rightHalf.size()){
            if(leftHalf[leftIndex] <= rightHalf[rightIndex]){
                ans.push_back(leftHalf[leftIndex]);
                leftIndex++;
            }else{
                ans.push_back(rightHalf[rightIndex]);
                rightIndex++;
            }
        }
        //For remaining elements in leftHalf and rightHalf, just add them directly at the end of ans..
        while(leftIndex < leftHalf.size()){
            ans.push_back(leftHalf[leftIndex]);
            leftIndex++;
        }
        while(rightIndex < rightHalf.size()){
            ans.push_back(rightHalf[rightIndex]);
            rightIndex++;
        }
        //Replace sorted array to nums
        for(int i = 0; i < ans.size(); i++){
            nums[low + i] = ans[i];
        }
    }

    void mergeSortHelper(vector<int>& nums, int low, int high){
        if(low >= high) return;
        int mid = low + (high - low)/2;
        mergeSortHelper(nums, low, mid);
        mergeSortHelper(nums, mid + 1, high);
        merge(nums, low, mid, high);
    }

    vector<int> mergeSort(vector<int>& nums) {
        if(nums.empty()) return nums;
        mergeSortHelper(nums, 0, nums.size() - 1);
        return nums;
    }
};
