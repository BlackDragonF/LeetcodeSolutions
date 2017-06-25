bool isPalindrome(int x) {
	if (x < 0) return false;
	if (x && x % 10 == 0) return false;
	int y = 0;
	while (x > y) {
		y *= 10;
		y += x % 10;
		x /= 10;
	}
	return (x == y) || (x == y / 10);
}
