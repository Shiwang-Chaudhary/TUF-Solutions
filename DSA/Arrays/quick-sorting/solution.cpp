class Solution {
public:

    int partition(vector<int>& nums, int start, int end){
        int pivEl = nums[end];
        int index = start - 1;
        for(int i = start; i <= end; i++){
            if(nums[i] < pivEl){
                index++;
                swap(nums[index], nums[i]);
            }
        }
        index++;
        swap(nums[index], nums[end]);
        return index; //pivotIndex
    }

    void qs(vector<int>& nums, int start, int end){
        if(start >= end) return;
        int pivotIndex = partition(nums, start, end);
        //This is for the elements less than pivot element
        qs(nums, start, pivotIndex - 1);
        //This is for the elements greater than pivot element
        qs(nums, pivotIndex + 1, end);
    }

    vector<int> quickSort(vector<int>& nums) {
        qs(nums, 0, nums.size() - 1);
        return nums;
    }
};
