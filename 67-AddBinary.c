char* addBinary(char* a, char* b) { 
	int aLen = strlen(a);
	int bLen = strlen(b);	
	int length = (aLen > bLen ? aLen : bLen) + 2;
	char temp[length];
	memset(temp, 0, sizeof(char) * length);	
	char * aPtr = a + aLen - 1;
	char * bPtr = b + bLen - 1;
	int flag = 0;
	int index = length - 2;	
	while (aPtr - a >= 0 && bPtr - b >= 0) {
		if (*aPtr == '1' && *bPtr == '1') {
			temp[index] = flag + '0';
			flag = 1;	
		} else if (*aPtr == '0' && *bPtr == '0') {
			temp[index] = flag + '0';
			flag = 0;
		} else {
			if (flag == 1) {
				temp[index] = '0';
			} else {
				temp[index] = '1';
			}
		}
		index--;
		aPtr--;
		bPtr--;
	}
	if (aPtr - a >= 0 || bPtr - b >= 0) {
		char * c;
		char * cPtr;
		if (aPtr - a >= 0) {
			c = a;
			cPtr = aPtr;
		} else {
			c = b;
			cPtr = bPtr;
		}
		while (cPtr - c >= 0) {
			if (*cPtr == '0') {
				temp[index] = flag + '0';
				flag = 0;
			} else {
				if (flag == 1) {
					temp[index] = '0';
				} else {
					temp[index] = '1';
				}
			}
			index--;
			cPtr--;
		}
	}
	if (flag == 1) {
		temp[index] = '1';
		index--;
	} 
	char * result = malloc(sizeof(char) * (length - index + 1));
	strcpy(result, temp + index + 1);
	return result;
}
