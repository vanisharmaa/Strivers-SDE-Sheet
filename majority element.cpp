/*
Given an array nums of size n, return the majority element.
The majority element is the element that appears more than ⌊n / 2⌋ times. You may assume that the majority element always exists in the array.
*/

int majorityElement(vector<int>& nums) {
    int el = 0, count = 0;
    int i = 0, n = nums.size();
    while(i < n){
        if(count == 0){
            el = nums[i];
            count++;
        }else if(nums[i] == el){
            count++;
        }else{
            count--;
        }
        i++;
    }
    return el;
}
