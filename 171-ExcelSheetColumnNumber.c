int titleToNumber(char* s) {
	int count = 0;
	char * temp = s;	
	while (*temp) {
		count++;
		temp++;
	}
	int index;
	int factor = 1;	
	int result = 0;
	for (index = count-1 ; index >= 0 ; --index) {
		result = result + factor * (s[index] - 'A' + 1);
		factor *= 26;
	}
	return result;	
}
