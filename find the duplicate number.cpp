/*
Given an array of integers nums containing n + 1 integers where each integer is in the range [1, n] inclusive.

There is only one repeated number in nums, return this repeated number.

You must solve the problem without modifying the array nums and uses only constant extra space.
*/
int findDuplicate(vector<int>& nums) {
    int fast = nums[0], slow = nums[0];
    do{
        fast = nums[nums[fast]];
        slow = nums[slow];
    }while(fast!=slow);
    fast = nums[0];
    while(slow != fast){
        slow = nums[slow];
        fast = nums[fast];
    }
    return slow;
}
