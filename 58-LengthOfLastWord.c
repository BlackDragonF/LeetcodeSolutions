int lengthOfLastWord(char* s) {
	int count = 0;
	int state = 0;
	char p;
	while (p = *s) {	
		if (state == 0 && p != ' ') {
			count = 1;
			state = 1;
		} else {
			if (state == 1) {
				if (p != ' ') {
					count++;
				} else {
					state = 0;
				}
			}
		}	
		s++;
	}
	return count;
}
