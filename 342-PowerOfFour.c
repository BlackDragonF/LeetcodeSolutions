bool isPowerOfTwo(int num) {
	if ((num > 0) && ((num & (num-1)) == 0)) {
		return true;
	}
	return false;
}

bool isPowerOfFour(int num) {
	if (isPowerOfTwo(num)) {
		if ((0x55555555 & num) != 0) {
			return true;
		}
	}
	return false;	
}
