int* twoSum(int* numbers, int numbersSize, int target, int* returnSize) {
    int * low = numbers;
    int * high = numbers + numbersSize - 1;
    while (*low + *high != target) {
        if (*low + *high > target) {
            high--;
        } else {
            low++;
        }
    }
    int * result = malloc(sizeof(int) * 2);
    *returnSize = 2;
    result[0] = low - numbers + 1;
    result[1] = high - numbers + 1;
    return result;
}
