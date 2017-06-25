int numberOfArithmeticSlices(int* A, int ASize) {
	if (ASize < 3) return 0;
	int result = 0;
	int count = 0;
	int index;
	for (index = 0 ; index < ASize - 2; ++index) {
		if (A[index] + A[index + 2] == 2 * A[index + 1]) {
			count++;
			result += count;
		} else {
			count = 0;
		}
	}
	return result;
}
