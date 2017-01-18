int reverse(int x) {
	long n = 0;
	int flag = (x > 0)?1:-1;
	x *= flag;	
	while (x) {
		n *= 10;	
		n += x % 10;
		x /= 10;
	}
	if (n * flag > INT_MAX || n * flag < INT_MIN) {
		return 0;
	}
	return n * flag;	
}

