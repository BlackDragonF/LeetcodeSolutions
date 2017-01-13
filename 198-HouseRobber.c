int rob(int* nums, int numsSize) {
    if (numsSize == 0) return 0;
    if (numsSize == 1) return nums[0];
    int results[numsSize];
    results[0] = nums[0];
    results[1] = (nums[1] > nums[0])?nums[1]:nums[0];
    int index, stat1, stat2;
    for (index = 2 ; index <= numsSize ; ++index) {
        stat1 = results[index - 1];
        stat2 = results[index - 2] + nums[index]; 
        if (stat1 > stat2) {
            results[index] = stat1;
        } else {
            results[index] = stat2;
        }
    }
    return results[numsSize - 1];
}
