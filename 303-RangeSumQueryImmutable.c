struct NumArray {
    int size;
    int * sums;
};

struct NumArray* NumArrayCreate(int* nums, int numsSize) {
    struct NumArray * numArray = malloc(sizeof(struct NumArray));
    numArray->size = numsSize;
    numArray->sums = malloc(sizeof(int) * (numsSize + 1));
    (numArray->sums)[0] = 0;
    int index;
    for (index = 1 ; index <= numsSize ; ++index) {
        (numArray->sums)[index] = (numArray->sums)[index-1] + nums[index - 1];
    }
    return numArray;
}

int sumRange(struct NumArray* numArray, int i, int j) {
    if (!numArray) 
        return 0;
    return (numArray->sums)[j+1] - (numArray->sums)[i];
}

void NumArrayFree(struct NumArray* numArray) {
    free(numArray->sums);
    free(numArray);
}
