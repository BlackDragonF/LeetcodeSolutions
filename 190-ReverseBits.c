uint32_t reverseBits(uint32_t n) {
	uint32_t result = 0U;
	int count;
	uint32_t bit;
	for (count = 0 ; count < 32 ; ++count) {
		result <<= 1;
		bit = n & 1;
		n >>= 1;
		result = result | bit;	
	}	
	return result;
}
