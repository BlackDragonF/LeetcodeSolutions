int findComplement(int num) {
	unsigned int mutable_mask = 0x80000000;
	int count = 0;	
	int result = ~num;
	int bit;
	while (bit = result & mutable_mask) {
		mutable_mask >>= 1;
		count++;
	}
	result = result & (~(0xffffffff << (32-count)));
	return result;
}

