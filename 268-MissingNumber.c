int missingNumber(int* nums, int numsSize) {
    int result = numsSize * (numsSize + 1) / 2;
    int index;
    for (index = 0 ; index < numsSize ; ++index) {
        result -= nums[index];
    }
    return result;
}
