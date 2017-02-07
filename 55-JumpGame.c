bool canJump(int* nums, int numsSize) {
    if (numsSize == 1) return true;
    int mark = numsSize - 1;
    int index;
    for (index = numsSize - 2 ; index >= 0 ; --index) {
        if (mark - index <= nums[index]) {
            mark = index;
        }
    }
    return (mark == 0);
}
