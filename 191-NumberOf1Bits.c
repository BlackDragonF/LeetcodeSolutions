int hammingWeight(uint32_t n) {
	int result = 0;
	int count;
	for (count = 0 ; count < 32 ; ++count) {
		if (n & 1U != 0) {
			result++;
		}
		n >>= 1;
	}
	return result;
}
