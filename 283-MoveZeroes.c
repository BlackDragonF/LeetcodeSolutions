void moveZeroes(int* nums, int numsSize) {
	int * zeroPtr = nums;
	int * otherPtr = nums;
	int temp;
	while (otherPtr - nums < numsSize) {
		while (*zeroPtr != 0) {
			zeroPtr++;
		}
		if (otherPtr-zeroPtr <= 0) otherPtr = zeroPtr;
		while (*otherPtr == 0) {
			otherPtr++;
			if (otherPtr - nums >= numsSize) return;
		}
		temp = *zeroPtr;
		*zeroPtr = *otherPtr;
		*otherPtr = temp;
		zeroPtr++;
		otherPtr++;
	}
}
