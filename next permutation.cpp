/*
A permutation of an array of integers is an arrangement of its members into a sequence or linear order.

For example, for arr = [1,2,3], the following are all the permutations of arr: [1,2,3], [1,3,2], [2, 1, 3], [2, 3, 1], [3,1,2], [3,2,1].
The next permutation of an array of integers is the next lexicographically greater permutation of its integer. More formally, if all the permutations of the array are sorted in one container according to their lexicographical order, then the next permutation of that array is the permutation that follows it in the sorted container. If such arrangement is not possible, the array must be rearranged as the lowest possible order (i.e., sorted in ascending order).

For example, the next permutation of arr = [1,2,3] is [1,3,2].
Similarly, the next permutation of arr = [2,3,1] is [3,1,2].
While the next permutation of arr = [3,2,1] is [1,2,3] because [3,2,1] does not have a lexicographical larger rearrangement.
Given an array of integers nums, find the next permutation of nums.

The replacement must be in place and use only constant extra memory.
*/
void nextPermutation(vector<int>& nums) {
    int n = nums.size();
    int ind1 = -1, ind2 = -1;
    for(int i = n-2; i >= 0; i--){
        if(nums[i] < nums[i+1]){
            ind1 = i;
            break;
        }
    }
    cout << ind1 << endl;
    if(ind1 == -1){
        sort(nums.begin(), nums.end());
        return;
    }
    for(int i = n-1; i>= 0; i--){
        if(nums[i] > nums[ind1]){
            ind2 = i;
            break;
        }
    }
    cout << ind2 << endl;
    swap(nums[ind1], nums[ind2]);
    sort(nums.begin()+ind1+1, nums.end());
}
