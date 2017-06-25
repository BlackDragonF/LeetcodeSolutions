char* addStrings(char* num1, char* num2) {
	char result[5102];
	memset(result, 0, sizeof(char) * 5102);
	char * s = num1, *t = num2;
	while (*s) s++;
	while (*t) t++;
	s--;
	t--;
	int flag = 0;
	int index;
	int sum = 0;	
	for (index = 5100 ; (s - num1 >= 0) || (t - num2 >= 0) ; --index) {
		if ((s - num1 >= 0) && (t - num2 >= 0)) {
			sum = *s + *t - 2 * '0' + flag;
		} else {
			if (s - num1 >= 0) {
				sum = *s - '0' + flag;
			} else {
				sum = *t - '0' + flag;
			}			
		}	
		flag = 0;
		if (sum >= 10) {
			sum -= 10;
			flag = 1;
		}
		result[index] = sum + '0';
		s--;
		t--;		
	}
	if (flag == 1) {
	    result[index] = '1';
	    index--;
	}
	char * result2 = malloc(sizeof(char) * (5101-index));
	strcpy(result2, result + index + 1);
	return result2;
}

