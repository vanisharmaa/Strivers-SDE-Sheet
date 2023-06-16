/*
  Given an integer array nums, return the number of reverse pairs in the array.
  
  A reverse pair is a pair (i, j) where:
  
  0 <= i < j < nums.length and
  nums[i] > 2 * nums[j].
*/

int merge(vector<int>& nums, int si1, int si2, int ei2){
    int ei1 = si2-1;
    int inv = 0;
    int i = si1, j = si2;
    while(i <= ei1 and j <= ei2){
        // in the next 3 lines using 2*nums[j] directly was causing a runtime error
        // due to the fact that 2*INT_MAX could not be contained in an INT variable
        // thats why i created a new variable called numsj that is of the type long long
        // and can store numbers > INT_MAX.
        long long numsj = nums[j];
        numsj += nums[j];
        if(nums[i] > numsj){
            inv += (si2-i);
            j++;
        }else{
            i++;
        }
    }
    i = si1, j = si2;
    vector<int> newNums(ei2-si1+1);
    int k = 0;
    while(i <= ei1 and j <= ei2){
        if(nums[i] < nums[j]){
            newNums[k++] = nums[i++];
        }else{
            newNums[k++] = nums[j++];
        }
    }
    while(i <= ei1){
        newNums[k++] = nums[i++];
    }
    while(j <= ei2){
        newNums[k++] = nums[j++];
    }
    for(int ind = si1; ind <= ei2; ind++){
        nums[ind] = newNums[ind-si1];
    }
    return inv;
}
int f(vector<int>& nums, int si, int ei){
    if(si >= ei){
        return 0;
    }
    int mid = (si + ei)/2;
    int inv = 0;
    inv += f(nums, si, mid);
    inv += f(nums, mid+1, ei);
    inv += merge(nums, si, mid+1, ei);
    return inv;
}
int reversePairs(vector<int>& nums) {
    int si = 0, ei = nums.size()-1;
    return f(nums, si, ei);
}
