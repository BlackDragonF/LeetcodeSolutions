int getSum(int a, int b) {
	int mutable_mask = 0x1;
	int a_bit, b_bit, flag = 0;
	int result = 0;	
	int count;
	for (count = 0 ; count < 32 ; count++) {
		a_bit = a & mutable_mask;
		b_bit = b & mutable_mask;
		if ((a_bit & b_bit) && (a_bit | b_bit)) {
			if (flag == 1) {
				result |= mutable_mask;
			}
			flag = 1;	
		}
		if ((a_bit | b_bit) && (a_bit ^ b_bit)) {
			if (flag == 0) {
				result |= mutable_mask;
			} else {
				flag = 1;
			}
		}
		if (!(a_bit & b_bit) && !(a_bit ^ b_bit)) {
			if (flag == 1) {
				result |= mutable_mask;
			}
			flag = 0;
		}
		mutable_mask <<= 1;
	}
	return result;
}
