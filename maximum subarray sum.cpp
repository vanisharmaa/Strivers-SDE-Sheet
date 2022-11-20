/*
Given an integer array nums, find the 
subarray
 which has the largest sum and return its sum.
*/
int maxSubArray(vector<int>& nums) {
    long localMax = nums[0],globalMax = nums[0];
    int n = nums.size();
    int i = 1;
    while(i < n){
        if(localMax < 0){
            localMax = 0;
        }
        localMax += nums[i];
        globalMax = max(globalMax, localMax);
        i++;
    }
    return globalMax;
}
