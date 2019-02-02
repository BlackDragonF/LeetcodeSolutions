class Solution {
public:
    int trailingZeroes(int n) {
        // 10 = 2 * 5, number of 2 >> number of 5
        // key is to calculate number of factor 5
        int number = n, result = 0;
        while (number >= 5) {
            number /= 5;
            result += number;
        }
        return result;
    }
};