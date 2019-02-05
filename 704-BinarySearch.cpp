class Solution {
public:
    int search(vector<int>& nums, int target) {
        int startIndex = 0, endIndex = nums.size();
        int index;
        while (startIndex <= endIndex) {
            index = startIndex + (endIndex - startIndex) / 2;

            if (nums[index] < target) {
                startIndex = index + 1;
            } else if (nums[index] > target) {
                endIndex = index - 1;
            } else {
                return index;
            }
        };

        return -1;
    }
};