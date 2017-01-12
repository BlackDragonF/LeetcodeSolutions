int countSegments(char* s) {
	int state = 1; //0-IN-SEGMENT 1-BETWEEN-SEGMENTS
	int count = 0;
	if (!*s) {
		return 0;
	}
	do {
		if (*s == ' ') {
			if (state == 0) {
				state = 1;
			}
		} else {
			if (state == 1) {
				state = 0;
				count++;
			}
		}
		s++;
	} while (*s);
	return count;
}
