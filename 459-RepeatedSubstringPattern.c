bool repeatedSubstringPattern(char* str) {
	int length = strlen(str);
	int count;
	bool flag;	
	int comp_a, comp_b;	
	for (count = length/2 ; count > 0 ; --count) {
		if (length % count == 0) {
			flag = true;
			comp_a = 0;
			comp_b = count;	
			while (flag && (comp_b + count) <= length) {
				flag = !strncmp(str+comp_a, str+comp_b, count);
				comp_b += count;
				comp_a += count;
			}
			if (flag) return true;
		}
	}
	return false;
}
