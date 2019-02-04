class Solution {
public:
    bool containsNearbyDuplicate(vector<int>& nums, int k) {
        map<int, int> numberHash;
        for (int index = 0; index < nums.size(); index++) {
            int number = nums[index];
            auto hashResult = numberHash.find(number);
            if (hashResult != numberHash.end()) {
                if (index - hashResult->second <= k) {
                    return true;
                }
            }
            numberHash[number] = index;
        }
        return false;
    }
};