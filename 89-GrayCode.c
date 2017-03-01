int* grayCode(int n, int* returnSize) {
    int * result = malloc(sizeof(int) * (1 << n));
    *returnSize = 1 << n;
    int mask;
    int temp;
    int index;
    for (index = 0 ; index < *returnSize ; ++index) {
        mask = 1 << (n - 1);
        temp = index;
        while (mask > 1) {
            temp &= ~(mask >> 1);
            temp |= ((index & mask) >> 1) ^ (index & (mask >> 1));
            mask >>= 1;
        }
        result[index] = temp;
    }
    return result;
}
