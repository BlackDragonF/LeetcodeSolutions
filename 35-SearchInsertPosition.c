int searchInsert(int* nums, int numsSize, int target) {
    int low = 0, high = numsSize - 1;
    int medium;
    while (low <= high) {
        medium = low + (high - low) / 2;
        if (nums[medium] == target) {
            return medium;
        } else if (nums[medium] < target) {
            low = medium + 1;
        } else {
            high = medium - 1;
        }
    }
    if (target < nums[medium]) {
        return medium;
    } else {
        return medium + 1;
    }
}
