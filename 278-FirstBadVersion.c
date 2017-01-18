bool isBadVersion(int version);

int firstBadVersion(int n) {
	int top = 1, bottom = n;
	if (isBadVersion(top)) {
		return 1;
	}
	int mid;
	bool result;	
	do {
		mid = top + (bottom - top) / 2;
		result = !isBadVersion(mid);
		if (result) {
			top = mid;
		} else {
			bottom = mid;
		}		
	} while (!(mid - top == 1 && !result) && !(bottom - mid == 1 && result));	
	return (result?bottom:mid);
}


