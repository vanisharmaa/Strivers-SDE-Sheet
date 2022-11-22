/*
Given an integer array of size n, find all elements that appear more than ⌊ n/3 ⌋ times.
*/
vector<int> majorityElement(vector<int>& nums) {
    int el1 = 0, c1 = 0, el2 = 0, c2 = 0;
    int i = 0, n = nums.size();
    while(i < n){
        if(c1 == 0 and el2 != nums[i]){
            el1 = nums[i];
            c1++;
        }
        else if(c2 == 0 and el1 != nums[i]){
            el2 = nums[i];
            c2++;
        }
        else if(el1 == nums[i]){
            c1++;
        }
        else if(el2 == nums[i]){
            c2++;
        }
        else{
            c1--;
            c2--;
        }
        i++;
    }
    int count1 = 0, count2 = 0; 
    for(int i = 0; i < n; i++){
        if(nums[i] == el1){
            count1++;
        }
        else if(nums[i] == el2){
            count2++;
        }
    }
    cout << el1 << " " << el2 << endl;
    vector<int> output;
    if(count1 > n/3){
        output.push_back(el1);
    }
    if(count2 > n/3){
        output.push_back(el2);
    }
    return output;
}
